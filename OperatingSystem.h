#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H


class OperatingSystem
{
    public:
        OperatingSystem();
        virtual ~OperatingSystem();
        void loadProgramForMemory (List<DataSegment> programData);
    protected:

    private:
        private int SYSTEM_MEMORY_SIZE = 2000;
        private CPU cpu;
        private Memory memory;
};

#endif // OPERATINGSYSTEM_H
