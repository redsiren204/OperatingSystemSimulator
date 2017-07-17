#include "IOModule.h"

#include <iostream>

using namespace std;

IOModule::IOModule()
{
    //ctor
}

static list<Instruction> readFile(string filePath)
{

}

static void print(int code, int mode)
{
    if (mode == 1)
    {
        cout << code;
    }
    else
    {
        cout << code;
    }
}

IOModule::~IOModule()
{
    //dtor
}
