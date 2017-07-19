#include "Timer.h"

Timer::Timer()
{
    //ctor
}

Timer::~Timer()
{
    //dtor
}

Timer::Timer(int tickTime)
{
    this->tickTime = tickTime;
    this->reset();
}

void Timer::setTickTime(int tickTime)
{
    this->tickTime = tickTime;
}

int Timer::getTickTime()
{
    return this->tickTime;
}

void Timer::setPriorityTimerInterrupt(int priority)
{
    this->piorityTimerInterrupt = priority;
}

int Timer::getPriorityTimerInterrupt()
{
    return this->piorityTimerInterrupt;
}

void Timer::updateTimer()
{
    this->counter++;
}

bool Timer::isHandlerTimerInterrupt()
{
    return (this->counter == tickTime);
}

void Timer::reset()
{
    this->counter = 0;
}
