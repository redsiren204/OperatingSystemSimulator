#ifndef REGISTER_H
#define REGISTER_H

#include <string>

using namespace std;

class Register
{
    public:
        Register();
        Register(string name);
        virtual ~Register();

        int getValue();
        void setValue(int value);

    protected:

    private:
        string name;
        int value;
};

#endif // REGISTER_H
