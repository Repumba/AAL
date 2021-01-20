#include <chrono>

class MeasureTime{


    public:
        MeasureTime();
        void startClock();
        void stopClock();
        int getTimeMilli();
        int getTimeMicro();
        int getTimeNano();

    private:
        std::chrono::time_point<std::chrono::steady_clock> start;
        std::chrono::time_point<std::chrono::steady_clock> end;
};

