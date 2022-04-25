#pragma once

#include <iostream>

#define UNDERLINE "\033[4m"

#define BLACK   "\033[1m\033[30m"      /* Bold Black : one  */ 
#define RED     "\033[1m\033[31m"      /* Bold Red : two  */
#define GREEN   "\033[1m\033[32m"      /* Bold Green : three */
#define YELLOW  "\033[1m\033[33m"      /* Bold Yellow : four */
#define BLUE    "\033[1m\033[34m"      /* Bold Blue : five */
#define CYAN    "\033[1m\033[36m"      /* Bold Cyan : six */
#define RESET   "\033[0m"

class instruction{
    private:
        int m_array[6];
    public:
        instruction();

        void print_instructions();

        void print_master_code(int array[4]);
        
        void print_master_code(int x, int y, int d, int z);

        void print_number(int number);


};
