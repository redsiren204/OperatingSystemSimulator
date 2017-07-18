#include <iostream>
#include <string>
#include <sstream>
#include <OperatingSystem.h>

using namespace std;

int main(int argc, char* argv[])
{
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
            cout << "Please set the timer" << endl;
            return 0;
        }
        break;

        case 3:
        {
            string program = argv[1];
            string time = argv[2];
            stringstream s(time);
            int timer = 0;
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

        default:
        break;
	}
    return 0;
}
