#pragma once

#include <iostream>
#include <random>

#include "Instruction.h"

class Breaker : public Instruction
{
    private:
        int m_code[4];
        int m_round;
    public: 

        Breaker();

        int get_random_num();
        void print_m_code(); // delete this later 

        int get_guess();
        

        void check_guess();
};