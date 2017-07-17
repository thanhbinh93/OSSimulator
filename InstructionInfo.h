#ifndef INSTRUCTIONINFO_H
#define INSTRUCTIONINFO_H


class InstructionInfo
{
    public:
        const LOAD_VALUE        =  1;
        const LOAD_ADDR         =  2;
        const LOAD_IND_ADDR     =  3;
        const LOAD_IDX_X_ADDR   =  4;
        const LOAD_IDX_Y_ADDR   =  5;
        const LOAD_SPX          =  6;
        const STORE_ADDR        =  7;
        const GET               =  8;
        const PUT_PORT          =  9;
        const ADD_X             = 10;
        const ADD_Y             = 11;
        const SUB_X             = 12;
        const SUB_Y             = 13;
        const COPY_TO_X         = 14;
        const COPY_FROM_X       = 15;
        const COPY_TO_Y         = 16;
        const COPY_FROM_Y       = 17;
        const COPY_TO_SP        = 18;
        const COPY_FROM_SP      = 19;
        const JUMP_ADDR         = 20;
        const JUMP_IF_EQUAL     = 21;
        const JUMP_IF_NOT_EQUAL = 22;
        const CALL_ADDR         = 23;
        const RET               = 24;
        const INCX              = 25;
        const DECX              = 26;
        const PUSH              = 27;
        const POP               = 28;
        const INT               = 29;
        const IRET              = 30;
        const END               = 50;

        InstructionInfo();
        InstructionInfo(int code, int num);
        virtual ~InstructionInfo();
        int getInstructionCode();
        void setInstructionCode(int code);
        int getNumOfOperands();
        void setNumOfOperands (int num);
        const InstructionSet* const instructionTable =
        {
            { LOAD_VALUE         , 1},
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
            { END                , 0}
        };

    protected:

    private:
        // Code of instruction
        int instructionCode;
        // Number of operands
        int numOfOperands;
};

#endif // INSTRUCTIONINFO_H
