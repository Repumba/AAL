#ifndef CLI_H
#define CLI_H


class UserInterface {

    public:

        // variables
        enum Mode{MANUAL, AUTO, TIME_TEST};
        enum Distribution {POISSON, UNIFORM};


        UserInterface(int argc, char** argv);
        ~UserInterface();
        void acquireData();

        int getCapacity();
        int getWorkers();
        int getUnitTimeCooking();
        int* getComingTimetamps();

        void setTotalTimeWait(int totalTime);
        void setFeedingTimestamps(int* feedingTimestamps);

        void printTotalTimeWait();
        void printFeedingTimestamps();

        // parsing
        [[nodiscard]] Mode getMode() const;
        [[nodiscard]] Distribution getDistribution() const;

        // bool matches(const T& test, Args&&... match)
        // {
        //     return ((test == match) || ...);
        // }


    private:
        int nWorkers;
        int capacity; // Maximum capasity of the oven
        int unitTimeCooking;

        int* comingTimestamps;

        int totalTimeWait;
        int* feedingTimestamps;

        Mode mode;
        Distribution distribution;

        // methods

        void parseCommands(int argc, char ** argv);
        void setMode(const std::string&& sMode);
        void setDistribution(const std::string&& sDistr);

        void setCapacity(int capacity);
        void setWorkers(int workers);
        void setUnitTimeCooking(int tCook);
        void setComingTimestamps(int * comingTimestamps);

        void printHelp() const;
};

#endif