#ifndef INSTRUCTIONSET_H
#define INSTRUCTIONSET_H


class InstructionSet
{
    public:
        InstructionSet();
        InstructionSet(int id, int numOfParam);
        virtual ~InstructionSet();
        int id;
        int numOfParam;
    protected:

    private:
};

#endif // INSTRUCTIONSET_H
