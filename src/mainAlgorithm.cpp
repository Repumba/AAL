#include <cassert>
#include "../include/mainAlgorithm.h"

using namespace std;

void Solver::setReadyTimes() {
    for (int i = 0; i < this->mSlices; ++i) {
        this->readySlicesTimes.push_back(this->unitTimeCooking);
    }
}

void Solver::optimize() {

    setReadyTimes();

    int workers = 0, i = 0, readySlices = 0;
    bool isWorkerWaiting = false;


    
    while (i < this->nWorkers) {

        int p;
        if (workers >= this->readySlicesTimes.size()) {
            p = INT_MAX;
        } else {
            p = this->readySlicesTimes[workers];
        }

        if (p <= this->comingTimestamps[i] || isWorkerWaiting) {
            if (isWorkerWaiting) {
                this->readySlicesTimes.push_back(p + this->unitTimeCooking);
                this->odp.push_back(p);
                ++i;
                isWorkerWaiting = false;
            } else {
                ++readySlices;
            }

            workers++;
        } else {
            if (readySlices > 0) {

                --readySlices;
                this->readySlicesTimes.push_back(this->comingTimestamps[i] + this->unitTimeCooking);
                this->odp.push_back(this->comingTimestamps[i]);

                ++i;
            } else {
                isWorkerWaiting = true;
            }
        }

    }

    // make an assertion
    // if (this->odp.size() != n) {
    //     std::cout << "Algorithm error" << std::endl;
    // }

    assert(this->odp.size() == this->nWorkers);

    countTotalWaitingTime();
    countFeedingTimestamps();
}

void Solver::countFeedingTimestamps() {
    for (int i = 0; i < this->nWorkers; ++i) {
        this->feedingTimestamps[i] = this->odp[i] - this->unitTimeCooking;
    }
}

void Solver::countTotalWaitingTime() {
    int sum = 0;
    for (int i = 0; i < this->nWorkers; ++i) {
        sum += (this->odp[i] - this->comingTimestamps[i]);
    }

    this->totalWaitingTime = sum;
}

int * Solver::getFeedingTimestamps() {
    return this->feedingTimestamps;
}


int Solver::getTotalWaitingTime() {
    return this->totalWaitingTime;
}


Solver::Solver(int nWorkers, int mSlices, int unitTimeCooking, int * comingTimestamps) {
    this->nWorkers = nWorkers;
    this->mSlices = mSlices;
    this->unitTimeCooking = unitTimeCooking;
    this->comingTimestamps = comingTimestamps;

    this->totalWaitingTime = 0;
    this->feedingTimestamps = new int[nWorkers];
}