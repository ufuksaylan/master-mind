#include "Computer.h"

int Computer::m_wins = 0;

Computer::Computer(vector<int> given_code) : NUM_COLOURS{6}, CODE_LENGTH{4},
currentGuess{1, 1, 2, 2}, turn{1}, won{false}
{
    code = given_code; 
}

void Computer::start_guessing()
{
    createSet();
    candidateSolutions.insert(candidateSolutions.end(), combinations.begin(), combinations.end());

    for (int i = 0; i < code.size(); ++i) {
        print_number(code[i]);
    }
    cout << "is your 'master code'.";
    cout << endl;

    while (!won) {

        //Remove currentGuess from possible solutions
        removeCode(combinations, currentGuess);
        removeCode(candidateSolutions, currentGuess);

        //Play the guess to get a response of colored and white pegs
        responsePegs = checkCode(currentGuess, code);

        cout << "Computer Turn #" << turn << ":" <<endl;
        
        for (int i = 0; i < currentGuess.size(); ++i) {
            print_number(currentGuess[i]);
        }
        cout << "Clues: " << highlight(responsePegs) << endl;

        //If the response is four colored pegs, the game is won
        if (responsePegs == "****") {
            m_wins++;
            won = true;
            cout << "Game over. The computer broke your code." << endl;
            break;
        }

        //Remove from candidateSolutions,
        //any code that would not give the same response if it were the code
        pruneCodes(candidateSolutions, currentGuess, responsePegs);

        //Calculate Minmax scores
        nextGuesses = minmax();

        //Select next guess
        currentGuess = getNextGuess(nextGuesses);

        turn++;
    }//End while
} 

void Computer::createSet() {

    vector<int> current(CODE_LENGTH, 0);
    vector<int> elements;

    for (int i = 1; i <= NUM_COLOURS; ++i) {
        elements.push_back(i);
    }

    combinationRecursive(CODE_LENGTH, 0, current, elements);
}

void Computer::combinationRecursive(int combinationLength, int position, vector<int> &current, vector<int> &elements) {

    if (position >= combinationLength) {
        combinations.push_back(current);
        return;
    }

    for (int j = 0; j < elements.size(); ++j) {
        current[position] = elements[j];
        combinationRecursive(combinationLength, position + 1, current, elements);
    }
    return;
}

string Computer::checkCode(vector<int> guess, vector<int> code) {

    string result;

    //Get black/coloured
    for (int i = 0; i < CODE_LENGTH; ++i) {

        if (guess[i] == code[i]) {
            result.append("*");
            guess[i] *= -1;
            code[i] *= -1;
        }
    }

    //Get white
    for (int i = 0; i < CODE_LENGTH; ++i) {

        if (code[i] > 0) {

            vector<int>::iterator it = find(guess.begin(), guess.end(), code[i]);
            int index;
            if (it != guess.end()) {

                index = distance(guess.begin(), it);
                result.append("&");
                guess[index] *= -1;
            }
        }
    }

    return result;
}

void Computer::removeCode(vector<vector<int>> &set, vector<int> currentCode) {

    int index;
    for (auto it = set.begin(); it != set.end(); it++) {
        index = distance(set.begin(), it);

        if (set[index] == currentCode) {
            set.erase(set.begin() + index);
            break;
        }
    }
}

void Computer::pruneCodes(vector<vector<int>> &set, vector<int> currentCode, string currentResponse) {

    int index;
    vector<vector<int>>::iterator it = set.begin();

    while (it != set.end()) {
        index = distance(set.begin(), it);

        if (currentResponse != checkCode(currentCode, set[index])) {
            it = set.erase(set.begin() + index);
        } else {
            it++;
        }
    }
}

vector<vector<int>> Computer::minmax() {

    map<string, int> scoreCount;
    map<vector<int>, int> score;
    vector<vector<int>> nextGuesses;
    int max, min;

    for (int i = 0; i < combinations.size(); ++i) {

        for (int j = 0; j < candidateSolutions.size(); ++j) {

            string pegScore = checkCode(combinations[i], candidateSolutions[j]);
            if (scoreCount.count(pegScore) > 0) {
                scoreCount.at(pegScore)++;
            } else {
                scoreCount.emplace(pegScore, 1);
            }
        }

        max = getMaxScore(scoreCount);
        score.emplace(combinations[i], max);
        scoreCount.clear();
    }

    min = getMinScore(score);

    for (auto elem : score) {
        if (elem.second == min) {
            nextGuesses.push_back(elem.first);
        }
    }

    return nextGuesses;
}

int Computer::getMaxScore(map<string, int> inputMap) {

    int max = 0;
    for (auto elem : inputMap) {
        if (elem.second > max) {
            max = elem.second;
        }
    }

    return max;
}

int Computer::getMinScore(map<vector<int>, int> inputMap) {

    int min = numeric_limits<int>::max();
    for (auto elem : inputMap) {
        if (elem.second < min) {
            min = elem.second;
        }
    }

    return min;
}

vector<int> Computer::getNextGuess(vector<vector<int>> nextGuesses) {

    vector<int> nextGuess;

    for (int i = 0; i < nextGuesses.size(); ++i) {
        if (find(candidateSolutions.begin(), candidateSolutions.end(), nextGuesses[i]) != candidateSolutions.end()) {
            return nextGuesses[i];
        }
    }
    for (int j = 0; j < nextGuesses.size(); ++j) {
        if (find(combinations.begin(), combinations.end(), nextGuesses[j]) != combinations.end()) {
            return nextGuesses[j];
        }
    }

    return nextGuess;
}

int Computer::get_wins(){
    return m_wins;
}