/**
 *  Register Class.
 */
#ifndef REGISTER_H
#define REGISTER_H

#include <string>

using namespace std;

class Register
{
    public:
        /**
         *  Register constructor.
         */
        Register();
        Register(string name);
        /**
         *  Register destructor.
         */
        virtual ~Register();

        /**
         *  Gets value from the register
         *  @return the value is an integer
         */
        int getValue();
        /**
         *  Sets value for the register
         *  @param value is an integer
         */
        void setValue(int value);

    protected:

    private:
        string name;
        int value;
};

#endif // REGISTER_H
