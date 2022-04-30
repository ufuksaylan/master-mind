#include "Game.h"

Game::Game() : m_exit{true}
{}

void Game::start(){

    while (m_exit)
    {
        Breaker person;
        m_base = &person; 
        /* 
        example of Polymorphism
        m_base pointer can point to either Breaker or Computer object.
        */

        person.print_instructions();

        int input; 
        std::cin >> input;

        while (std::cin.fail() || (input != 1 && input != 2))
        {
            std::cout << highlight("You should type either 1 or 2.") 
            << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> input;
        }

        if (input == 1)
        {
            computer_solve();
            continue;
        }

        for (int i = 0; i < 12; i++)
        {
            if (person.check_guess())
            {
                break;
            }
        }
        
        m_exit = play_again();

    }
}

void Game::computer_solve() 
{
    std::cout << "Please enter a 4-digit 'master code' for the computer to break." << std::endl;

    int code; 
    std::cin >> code;

    while (std::cin.fail() || (!std::cin.fail() && m_person1.check_digits(code) != 4))
    {
        std::cout << highlight("Your guess should only be 4 digits between 1-6.\n") 
        << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> code;
    }

    vector<int> code_vec(4);

    for (int i = 3; i >= 0; i--) {
        code_vec[i] = code % 10;
        code /= 10;
    }

    Computer ai(code_vec);
    ai.start_guessing();

    m_exit = play_again();

}
bool Game::play_again(){

    std::cout << "Do you want to play again? Press 'y' for yes (or any other key for no).\n";
    std:string y; 
    std::cin >> y;

    if (y == "y")
        return true;
    else
    {
        std::cout << "Your total wins: " << m_base->get_wins() << std::endl;
        
        // Now m_base points computer object.
        m_base = &m_ai;
        
        std::cout << "Computer's total wins: " << m_base->get_wins() << std::endl;
    }
    return false;
}

