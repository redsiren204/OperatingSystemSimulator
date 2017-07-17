#include "Timer.h"

Timer::Timer()
{
    this->step = 1;
}

Timer::Timer(int step)
{
    this->step = step;
}

int Timer::getStep()
{
    return step;
}

Timer::~Timer()
{
    //dtor
}
