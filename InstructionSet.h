#ifndef INSTRUCTIONSET_H
#define INSTRUCTIONSET_H

/**
    Define information for a instruction
    A set instruction contain: code and operand
*/
class InstructionSet
{
    public:
        InstructionSet();

        /**
         * Initiate a instruction with parameters
         * @param optCode code of a instruction set
         * @param numOfOperand number of operand for a instruction
         *
         */
        InstructionSet(int optCode, int numOfOperand);
        virtual ~InstructionSet();

        /**
         * Instruction's code, always is integer number
         */
        int optCode;

        /**
         * Number of operand for a instruction
         */
        int numOfOperand;

        /**
         * Save operands of instruction
         */
        int operands[10];

    protected:

    private:
};

#endif // INSTRUCTIONSET_H
