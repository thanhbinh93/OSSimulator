#include <cstdio>
#include <stdlib.h>
#include "OSSimulator.h"

using namespace std;

int main(int argc, char* argv[])
{

    OSSimulator ossimulator;
    ossimulator.run(argc, argv);

    std::getchar();
    return 1;
}
