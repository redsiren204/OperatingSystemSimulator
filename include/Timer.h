/**
 *  Timer class.
 *  A timer will interrupt the processor after every X instruction, where X is a command-line parameter.
 */
#ifndef TIMER_H
#define TIMER_H


class Timer
{
    public:
        /**
         *  Timer constructor.
         */
        Timer();
        /**
         *  Timer destruction with argument
         *  @param step is an integer
         */
        Timer(int step);
        /**
         *  Timer destructor.
         */
        virtual ~Timer();

        /**
         *  Gets step function
         *  @return step is an integer
         */
        int getStep();

    protected:

    private:
        /**
         *  Declare step variable.
         */
        int step;
};

#endif // TIMER_H
