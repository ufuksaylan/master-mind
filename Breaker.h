#pragma once

#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>

#include "Instruction.h"

class Breaker : public Instruction
{
    private:
        int m_code[4];
        int m_round; 
        static int m_wins;
        
        int check_digits(int x);


    public: 

        Breaker();

        int get_random_num();
        void print_m_code(); // delete this later 

        int get_guess();


        void check_guess();

        int get_wins() override;
};