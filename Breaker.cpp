#include "Breaker.h"

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

void Breaker::print_m_code(){
    std::cout << m_code[0] << "\t" << m_code[1] << "\t"
    << m_code[2] << "\t" << m_code[3] << std::endl;
}

int Breaker::get_guess(){
    
    std::cout << "\nTurn #" << m_round 
    << ": Type in four numbers (1-6) to guess code, or 'q' to quit game."
    << std::endl; 

    int input; 
    std::cin >> input;

    while (std::cin.fail() || (!std::cin.fail() && ))
    {
        std::cout << highlight("Your guess should only be 4 digits between 1-6.") 
        << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> input;
    }
    

    return 5; 
}