#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

#include "Memory.h"
#include "IndexOutOfRangeException.h"
#include "LineInstruction.h"

using namespace std;

Memory::Memory()
{
    //ctor
}

Memory::~Memory()
{
    //dtor
}

void Memory::initialize(string filePath)
{
    string line = "";
    ifstream programFile(filePath.c_str());

    int address = 0;
    if (programFile.is_open())
    {
        while(getline(programFile, line))
        {
            line = trim(line);

            if (isFullUserMemory(address)) throw IndexOutOfRangeException();

            if (isNotEmptyLine(line) && isCommandLine(line))
            {
                int instruction = getInstructionFromLine(line);
                write(address++, instruction);
            }
        }

        programFile.close();
    }
}

string Memory::trim (string line)
{
    string trimLine = "";
    for (int i = 0; i < line.length(); i++)
    {
        char temp = line.at(i);
        if (temp !=  ' ' && temp != '\t' && temp != '\n')
        {
            trimLine = trimLine + temp;
        }
    }
    return trimLine;
}


bool Memory::isFullUserMemory(int address)
{
    return address > 1000;
}


int Memory::getInstructionFromLine(string line)
{
    LineInstruction lineConstruction(line);
    int optCode = lineConstruction.detectOptCode();
    return optCode;
}


bool Memory::isCommandLine (string line)
{
    char firstLetter = ' ';

    if (line.length() > 0)
    {
        firstLetter = line.at(0);
    }
    bool isBeginByNumber = isdigit(firstLetter) == 1;
    bool isBeginByHypen = firstLetter == '-';

    return isBeginByHypen || isBeginByNumber;
}

bool Memory::isNotEmptyLine (string line)
{
    return line.length() != 0;
}


int Memory::read(int address)
{
    if (address < 0 || address > SIZE_OF_MEMORY)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        return memory[address];
    }
}


void Memory::write(int address, int value)
{
    if (address < 0 || address > SIZE_OF_MEMORY)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        memory[address] = value;
    }
}
