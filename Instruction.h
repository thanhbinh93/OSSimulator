#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "InstructionSet.h"
#include <list>

/**
* Define constant for Opt code of Instruction command
*/
#define LOAD_VALUE          1
#define LOAD_ADDR           2
#define LOAD_IND_ADDR       3
#define LOAD_IDX_X_ADDR     4
#define LOAD_IDX_Y_ADDR     5
#define LOAD_SPX            6
#define STORE_ADDR          7
#define GET                 8
#define PUT_PORT            9
#define ADD_X              10
#define ADD_Y              11
#define SUB_X              12
#define SUB_Y              13
#define COPY_TO_X          14
#define COPY_FROM_X        15
#define COPY_TO_Y          16
#define COPY_FROM_Y        17
#define COPY_TO_SP         18
#define COPY_FROM_SP       19
#define JUMP_ADDR          20
#define JUMP_IF_EQUAL      21
#define JUMP_IF_NOT_EQUAL  22
#define CALL_ADDR          23
#define RET                24
#define INCX               25
#define DECX               26
#define PUSH               27
#define POP                28
#define INT                29
#define IRET               30
#define END                50
#define NUMBER_OF_INSTRUCTION 31

using namespace std;
class Instruction
{
    public:
        Instruction();
        virtual ~Instruction();

        /**
        * Declare array contain all instruction command
        */
        InstructionSet instructions [100] = {{ LOAD_VALUE         , 1},
                                             { LOAD_ADDR          , 1},
                                             { LOAD_IND_ADDR      , 1},
                                             { LOAD_IDX_X_ADDR    , 1},
                                             { LOAD_IDX_Y_ADDR    , 1},
                                             { LOAD_SPX           , 1},
                                             { STORE_ADDR         , 1},
                                             { GET                , 0},
                                             { PUT_PORT           , 1},
                                             { ADD_X              , 0},
                                             { ADD_Y              , 0},
                                             { SUB_X              , 0},
                                             { SUB_Y              , 0},
                                             { COPY_TO_X          , 0},
                                             { COPY_FROM_X        , 0},
                                             { COPY_TO_Y          , 0},
                                             { COPY_FROM_Y        , 0},
                                             { COPY_TO_SP         , 0},
                                             { COPY_FROM_SP       , 0},
                                             { JUMP_ADDR          , 1},
                                             { JUMP_IF_EQUAL      , 1},
                                             { JUMP_IF_NOT_EQUAL  , 1},
                                             { CALL_ADDR          , 1},
                                             { RET                , 0},
                                             { INCX               , 0},
                                             { DECX               , 0},
                                             { PUSH               , 0},
                                             { POP                , 0},
                                             { INT                , 0},
                                             { IRET               , 0},
                                             { END                , 0}};

    protected:

    private:

};

#endif // INSTRUCTION_H
