#pragma once
#include <iostream>

#define UNDERLINE "\033[4m"

#define BLACK   "\033[1m\033[30m"      /* Bold Black */
#define RED     "\033[1m\033[31m"      /* Bold Red */
#define GREEN   "\033[1m\033[32m"      /* Bold Green */
#define YELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BLUE    "\033[1m\033[34m"      /* Bold Blue */
#define CYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define RESET   "\033[0m"

class instruction{
    private:
        
    public:
        void print_instructions();

};
