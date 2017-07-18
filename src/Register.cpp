#include "Register.h"

Register::Register()
{
    this->name = "No name";
    this->value = 0;
}

Register::Register(string name)
{
    this->name = name;
    this->value = 0;
}

int Register::getValue()
{
    return value;
}

void Register::setValue(int value)
{
    this->value = value;
}

Register::~Register()
{

}
