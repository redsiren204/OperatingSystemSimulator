#include "IOModule.h"

#include <iostream>
#include <stdio.h>

using namespace std;

IOModule::IOModule()
{

}

void IOModule::display(int code, int mode)
{
    if (mode == 1)
    {
        printf("%d", code);
    }
    else
    {
        printf("%c", code);
    }
}

IOModule::~IOModule()
{

}
