#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "ArgumentException.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Convert argument to variable
    try
    {
        // If parameter is invalid, set default value
        if (argc < 3)
        {
            throw ArgumentException();
        }
        else
        {
            string filePath = std::string(argv[1]);

            int tickTime = 0;
            sscanf (argv[2],"%d",&tickTime);

            if (tickTime == 0)
            {
                throw ArgumentException();
            }
            else
            {
                cout << "Begin run program with: " << endl;
                cout << "A timer will interrupt the processor after every " << tickTime << " instruction" << endl;
                cout << "Program file will be read from " << filePath << endl;
                /*
                File programFile = new File(filePath);
                OperatingSystem operatingSystem = new OperatingSystem();
                // Read program file
                List<DataSegment> programData = SegmentParser.parseFile(programFile);
                // Load program data to memory
                operatingSystem.loadProgram(programData);
                // Set timer period
                operatingSystem.setTimer(tickTime);
                // start simulation
                operatingSystem.start();
                */
            }
        }
    }
    catch (ArgumentException e)
    {
        cout << e.what() << endl;
    }

    std::getchar();
    return 1;
}
