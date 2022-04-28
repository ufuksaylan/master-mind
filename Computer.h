/* 
This is the implentation of https://github.com/nattydredd/Mastermind-Five-Guess-Algorithm 
into to Computer class. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <ctime>
#include "Instruction.h"

using namespace std;

class Computer : public Instruction
{
    private:
        const int NUM_COLOURS = 6;
        const int CODE_LENGTH = 4;
        vector<vector<int>> combinations; //Master set of combinations 1111 to 6666
        vector<vector<int>> candidateSolutions;
        vector<vector<int>> nextGuesses;
        vector<int> code;
        vector<int> currentGuess;
        string responsePegs;
        bool won;
        int turn;

    public:

        Computer(vector<int> given_code);

        void createSet();

        void combinationRecursive(int combinationLength, int position, vector<int> &current, vector<int> &elements);

        string checkCode(vector<int> guess, vector<int> code);

        void removeCode(vector<vector<int>> &set, vector<int> code);

        void pruneCodes(vector<vector<int>> &set, vector<int> code, string currentResponse);

        vector<vector<int>> minmax();

        int getMaxScore(map<string, int> inputMap);

        int getMinScore(map<vector<int>, int> inputMap);

        vector<int> getNextGuess(vector<vector<int>> nextGuesses);

        void start_guessing();

};