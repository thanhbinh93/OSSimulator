#ifndef LINEINSTRUCTION_H
#define LINEINSTRUCTION_H
#include <string>

using namespace std;

/**
 * Define instruction for one line
 *
 */

class LineInstruction
{
    public:
        LineInstruction();

        /**
         * Initiate a line instruction for a line
         * @param line will be parse
         *
         */
        LineInstruction(string line);
        virtual ~LineInstruction();

        /**
         * Get a line
         *
         */
        string getLine();

        /**
         * Set value for a line
         *
         */
        void setLine(string line);

        /**
         * Detect code for a line
         * @return code of instruction line
         */
        int detectOptCode();

        /**
         * Read array char which contain code characters
         * @param instruction array contains code
         * @param len is length of array
         * @return code is calculate from arrays
         */
        int convertCharToOptCode(char* intructions);

    protected:

    private:
        string line;
};

#endif // LINEINSTRUCTION_H
