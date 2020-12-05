#include <vector>
#include <climits>

class Solver {

    private:

        int nWorkers;
        int mSlices;
        int unitTimeCooking;
        int * comingTimestamps;

        int totalWaitingTime;
        int* feedingTimestamps;

        std::vector<int> odp;
        std::vector<int> readySlicesTimes;

    public:

        void setReadyTimes();
        void optimize();
        int * getFeedingTimestamps();
        void countTotalWaitingTime();
        void countFeedingTimestamps();
        int getTotalWaitingTime();

        Solver(int nWorkers, int mSlices, int unitTimeCooking, int * comingTimestamps);
};