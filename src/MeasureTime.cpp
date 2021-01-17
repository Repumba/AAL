#include "../include/MeasureTime.h"

MeasureTime::MeasureTime(){
    
}
void MeasureTime::startClock(){
    start =std::chrono::steady_clock::now();
}

void MeasureTime::stopClock(){
    end = std::chrono::steady_clock::now();
}

int MeasureTime::getTimeMilli(){
    return std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();
}

int MeasureTime::getTimeMicro(){
    return std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
}

int MeasureTime::getTimeNano(){
    return std::chrono::duration_cast<std::chrono::nanoseconds>( end - start ).count();
}