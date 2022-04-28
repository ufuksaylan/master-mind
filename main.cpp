#include <iostream>
#include "Instruction.h"
#include "Breaker.h"
#include "Computer.h"

int main()
{
    // int x; 
    // Instruction a; 

    // a.print_instructions();

    // Breaker b; 

    // // b.print_m_code();
    // // b.get_guess();
    // for (int i = 0; i < 12; i++)
    // {
    //     b.check_guess();

    // }
    
    //std::cout << b.get_random_num();
    vector<int> code={6,3,4,5};

    Computer ai(code);
    ai.start_guessing();
    
    return 0;
    
}
