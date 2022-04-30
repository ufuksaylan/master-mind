#include "Computer.h"
#include "Instruction.h"
#include "Breaker.h"

#include <string>
#include <iostream>

class Game{
    private:
        Breaker m_person1; 
        bool m_exit;
        Computer m_ai;
        Instruction *m_base;
    public: 
        Game();
        void start();  
        void computer_solve();
        bool play_again();
        bool play_again(Computer& pc);

};