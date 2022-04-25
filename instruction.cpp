#include "instruction.h"

instruction::instruction(): m_array {1, 2, 3, 4, 5, 6}
{

}

void instruction::print_number(int number){
    switch (number)  {
    case 1:
        std::cout << BLACK << 1 << RESET << "\t";
        break;

    case 2:
        std::cout << RED << 2 << RESET << "\t";
        break;

    case 3:
        std::cout << GREEN << 3 << RESET << "\t";
        break;

    case 4:
        std::cout << YELLOW << 4 << RESET << "\t";
        break;

    case 5:
        std::cout << BLUE << 5 << RESET << "\t";
        break;

    case 6:
        std::cout << CYAN << 6 << RESET << "\t";
        break;   
    }         
}

void instruction::print_master_code(int array[4]){
    
    for (int i = 0; i < 4; i++)
    {
        print_number(array[i]);
    }
}

void instruction::print_master_code(int x, int y, int d, int z){
    print_number(x); 
    print_number(y); 
    print_number(d); 
    print_number(z);
}

void instruction::print_instructions(){

    using std::cout; 
    
    cout << underline("How to play Mastermind:\n") 
    << "\nThis is a 1-player game against the computer.\n"
    << "You can choose to be the code " << underline("maker") 
    << " or the code " << underline("breaker") << ".\n"
    << "\n\nThere are six different number/color combinations:\n"
    << one << "\t" << two << "\t" << three << "\t" << four << "\t" << five << "\t" << six
    << "\n\nThe code maker will choose four to create a 'master code'. For example,\n"
    << one << "\t" << three << "\t" << four << "\t" << one
    << "\n\nAs you can see, there can be " << highlight("more then one") 
    << " of the same number/color."
    << "\nIn order to win, the code breaker needs to guess the 'master code' in 12 or less turns."
    << "\n\n" << underline("Clues:") 
    << "\nAfter each guess, there will be up to four clues to help crack the code.\n\n"
    << highlight("*") << " This clue means you have 1 correct number in the correct location."
    << highlight("&") << " This clue means you have 1 correct number, but in the wrong location.\n\n"
    << underline("Clue Example:") 
    << "\nTo continue the example, using the above 'master code' a guess of '1463' would produce 3 clues:\n\n"
    << one << "\t" << four << "\t" << six << '\t' << three
    << "  Clues: " << highlight("*") << " " << highlight("&") << " " << highlight("&")
    << "\n\nThe guess had 1 correct number in the correct location and 2 correct numbers in a wrong location.\n\n"
    << underline("It's time to play!")
    << "\nWould you like to be the code MAKER or code BREAKER?\n\n"
    << "Press '1' to be the code MAKER\n"
    << "Press '2' to be the code BREAKER" << std::endl; 

}