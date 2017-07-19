#ifndef OSSIMULATOR_H
#define OSSIMULATOR_H

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cstring>

using namespace std;

/**
 * Control terminal command line to run program
 *
 */

class OSSimulator
{
    public:
        OSSimulator();
        virtual ~OSSimulator();

        /**
         *
         * Run process with parameters which is inputed from terminal
         * @param argc is number of parameters
         * @param argv[] is parameters
         */
        void run(int argc, char* argv[]);

        /**
         *
         * Run process with parameters which is inputed from terminal
         * @param argc is number of parameters
         * @param argv[] is parameters
         */
         int paserTickTime(char* p);

    protected:

    private:
};

#endif // OSSIMULATOR_H
