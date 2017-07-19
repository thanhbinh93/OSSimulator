#ifndef TIMER_H
#define TIMER_H

/**
 * A timer will interrupt the processor after every X instruction,
 * where X is a command-line parameter.
 *
 * @author
 */
class Timer
{
    public:
        /**
         * Constructor for Timer class
         *
         */
        Timer();

        /**
         * Destructor for Timer class
         *
         */
        virtual ~Timer();

        /**
         * Constructor for Timer class with tick time
         *
         */
        Timer(int tickTime);

        /**
         * Set tick time
         *
         */
        void setTickTime(int tickTime);

        /**
         * Get tick time
         *
         */
        int getTickTime();

        /**
         * Set priority processing timer interrupt or program interrupt
         *
         */
        void setPriorityTimerInterrupt(int priority);

        /**
         * Get priority processing timer interrupt or program interrupt
         *
         */
        int getPriorityTimerInterrupt();

        /**
         * counter time
         *
         */
        void updateTimer();

        /**
         * checking handler timer interrupt
         *
         */
        bool isHandlerTimerInterrupt();

        /**
         * restore initial state of Timer
         *
         */
        void reset();

    protected:

    private:
        /**
         * variable counter as determine current time
         *
         */
        int counter;

        /**
         * tick time interrupt
         *
         */
        int tickTime = 30;

        /**
         * Priority processing timer interrupt or program interrupt
         *
         */
        int piorityTimerInterrupt = 0;
};

#endif // TIMER_H
