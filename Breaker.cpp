#include "Breaker.h"

int Breaker::m_wins = 0;


Breaker::Breaker() : m_code {get_random_num(), get_random_num(), 
get_random_num(), get_random_num()}, m_round{1} 
{
    std::cout << "\nThe computer has set the 'master code' and now it's time for you to break the code."
    << std::endl;
}

int Breaker::get_random_num(){

    std::random_device rd;     
    std::mt19937 rng(rd());    
    std::uniform_int_distribution<int> uni(1,6); 
    
    return uni(rng);
}

int Breaker::get_guess(){
    
    std::cout << "\nTurn #" << m_round 
    << ": Type in four numbers (1-6) to guess code, or '-1' to quit game."
    << std::endl; 

    int input; 
    std::cin >> input;

    // put a usefull return statement 
    if (input == -1)
    {
        std::cout << "exit";
        exit (0);
    }

    while (std::cin.fail() || (!std::cin.fail() && check_digits(input) != 4))
    {
        std::cout << highlight("Your guess should only be 4 digits between 1-6.") 
        << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> input;
        if (input == -1)
        {
            std::cout << "exit";
            exit (0);
        }
    }

    m_round++;
    return input; 
}

int Breaker::check_digits(int x)
{
    int digits = 0; 
    while (x != 0) 
    { 
        x /= 10; 
        digits++; 
    }
    return digits;
}

void Breaker::check_guess()
{
    int copy_code[4];
    std::copy(std::begin(m_code), std::end(m_code), std::begin(copy_code));

    int guess = get_guess();
    
    int guess_arr[4];
    for (int i = 3; i >= 0; i--) {
        guess_arr[i] = guess % 10;
        guess /= 10;
    }

    print_master_code(guess_arr);
    
    int same_location = 0;
    int contain = 0;

    check_matches(copy_code, guess_arr, same_location, contain);

    // Put a useful return statement here
    if (same_location == 4)
    {
        m_wins++;
        std::cout << "you broke the code";
    }

    print_clue(same_location, contain);

    print_m_code(); // delete this later 
}

void Breaker::print_m_code(){
    std::cout << m_code[0] << "\t" << m_code[1] << "\t"
    << m_code[2] << "\t" << m_code[3] << std::endl;
}

int Breaker::get_wins(){
    return m_wins;
}