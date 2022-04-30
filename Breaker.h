#pragma once

#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>

#include "Instruction.h"

class Breaker : public Instruction
{
    protected:
        int m_code[4];
        int m_round; 
        static int m_wins;
        
        


    public: 

        Breaker();
        int check_digits(int x);
        int get_random_num();
        void print_m_code(); // delete this later 

        int get_guess();


        bool check_guess();

        int get_wins() override;

        void operator+(); 
};