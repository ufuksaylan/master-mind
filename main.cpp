#include <iostream>
#include "Instruction.h"
#include "Breaker.h"

int main()
{
    int x; 
    Instruction a; 

    a.print_instructions();

    Breaker b; 

    // b.print_m_code();
    // b.get_guess();
    for (int i = 0; i < 12; i++)
    {
        b.check_guess();

    }
    
    //std::cout << b.get_random_num();
 
    return 0;
    
}
