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

    int array[4] = {4, 2, 3, 4};

    cout << UNDERLINE << "How to play Mastermind:\n" << RESET <<
    R"V0G0N(
This is a 1-player game against the computer.
You can choose to be the code maker or the code breaker.

There are six different number/color combinations:
)V0G0N";

    for (int i = 1; i <= 6; i++)
    {
        print_number(i);
    }
    
    cout << "\n\n\nThe code maker will choose four to create a 'master code'. For example,\n"; 

    print_master_code(array);

    cout << R"V0G0N(

As you can see, there can be more then one of the same number/color.
In order to win, the code breaker needs to guess the 'master code' in 12 or less turns.
)V0G0N";

    cout << UNDERLINE << "\n\nClues:\n" << RESET <<
     "After each guess, there will be up to four clues to help crack the code.\n";


}