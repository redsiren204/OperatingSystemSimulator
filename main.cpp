#include <iostream>
#include <string>
#include <sstream>
#include <OperatingSystem.h>

using namespace std;

int main(int argc, char* argv[])
{
    string program;
    int timer = 0;

    switch (argc)
	{
        case 1:
        {
            cout << "Missing arguments for program file and timer" << endl;
            return 0;
        }
        break;

        case 2:
        {
            program = argv[1];
            cout << "Please set the timer" << endl;
            return 0;
        }
        break;

        case 3:
        {
            program = argv[1];
            string time = argv[2];
            stringstream s(time);
            s >> timer;
            cout << "Program : " << program << endl;
            cout << "Timer : " << timer << endl;

            /**
             *  Creates a operating system and run
             */
            OperatingSystem osSim = OperatingSystem(program, timer);
            osSim.run();
        }
        break;
	}
    return 0;
}
