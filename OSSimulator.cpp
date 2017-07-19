#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cstring>

#include "ArgumentException.h"
#include "OperatingSystem.h"
#include "IndexOutOfRangeException.h"
#include "NotSupportedInstructionException.h"
#include "OSSimulator.h"
#include "IllegalAccessMemoryException.h"

using namespace std;

OSSimulator::OSSimulator()
{
    //ctor
}

OSSimulator::~OSSimulator()
{
    //dtor
}

void OSSimulator::run(int argc, char* argv[])
{
    // Convert argument to variable
    try
    {
        // If parameter is invalid, set default value
        if(argc < 3 ) throw ArgumentException();
        if(std::string(argv[1]) != "ossimulator") throw ArgumentException();

        string filePath = std::string(argv[2]);
        int tickTime = this->paserTickTime(argv[3]);

        cout << "Begin run program" << endl;
        OperatingSystem operatingSystem;
        operatingSystem.loadProgramForMemory(filePath);
        operatingSystem.start(tickTime);
    }
    catch (ArgumentException argEx)
    {
        cout << argEx.what() << endl;
    }
    catch (IndexOutOfRangeException indexEx)
    {
        cout << indexEx.what() << endl;
    }
    catch (NotSupportedInstructionException notSupportedEx)
    {
        cout << notSupportedEx.what() << endl;
    }
    catch(IllegalAccessMemoryException illegalEx)
    {
        cout << illegalEx.what() << endl;
    }

}

int OSSimulator::paserTickTime(char* p)
{
    int nr = 0;
    int i;
    for(i =0; i< strlen(p); i++) {
        nr = 10 * nr + p[i] - '0';
    }
    if(nr <= 0) throw ArgumentException();
    return nr;
}
