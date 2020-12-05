class UserInterface {

    public:

        UserInterface();
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


    private:
        int nWorkers;
        int capacity; // Maximum capasity of the oven
        int unitTimeCooking;

        int* comingTimestamps;

        int totalTimeWait;
        int* feedingTimestamps;

};