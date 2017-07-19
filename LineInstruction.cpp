#include "LineInstruction.h"
#include <tgmath.h>
#include <stdio.h>
#include <iostream>
#include <cctype>

using namespace std;

LineInstruction::LineInstruction()
{
    //ctor
}

LineInstruction::LineInstruction(string line)
{
    this->line = line;
}


LineInstruction::~LineInstruction()
{
    //dtor
}

string LineInstruction::getLine()
{
    return this->line;
}

void LineInstruction::setLine(string line)
{
    this->line = line;
}

int LineInstruction::detectOptCode()
{
    char tempInstruction[100];
    bool isNotEndDetect = true;
    int index = 0;

    while (isNotEndDetect && index < line.length())
    {
        char temp = this->line.at(index);
        if (isdigit(temp) == 1 || temp == '-')
        {
            tempInstruction[index] = temp;
            index++;
        }
        else
        {
            isNotEndDetect = false;
        }
    }

    return convertCharToOptCode(tempInstruction);
}


int LineInstruction::convertCharToOptCode(char* intructions)
{
    int optCode = 0;
    sscanf(intructions, "%d", &optCode);

    return optCode;
}
