#include <iostream>

#include "cli.h"


using namespace std;

UserInterface::UserInterface() {

}


void UserInterface::acquireData() {

    /*
        A method to get data from user
    */

    cout << "Podaj liczbe pracownikow" << endl;
    cin >> this->nWorkers;

    cout << "Podaj pojemnosc mikrofalowki" << endl;
    cin >> this->capacity;

    cout << "Podaj czas podgrzewania 1 kawalka pizzy" << endl;
    cin >> this->unitTimeCooking;

    cout << "Podaj momenty przyjscia pracownikow do kuchni" << endl;

    this->comingTimestamps = new int[this->nWorkers];
    for (int i = 0; i < this->nWorkers; ++i) {
        cin >> this->comingTimestamps[i];
    }
}

// Getters and setters

int UserInterface::getWorkers() {
    return this->nWorkers;
}

int UserInterface::getCapacity() {
    return this->capacity;
}

int UserInterface::getUnitTimeCooking() {
    return this->unitTimeCooking;
}

int* UserInterface::getComingTimetamps() {
    return this->comingTimestamps;
}

UserInterface::~UserInterface() {
    delete comingTimestamps;
}


void UserInterface::setTotalTimeWait(int totalTime) {
    this->totalTimeWait = totalTime;
}

void UserInterface::setFeedingTimestamps(int* feedingTimestamps) {
    this->feedingTimestamps = feedingTimestamps;
}

void UserInterface::printTotalTimeWait() {
    cout << this->totalTimeWait;
    cout << endl;
}

void UserInterface::printFeedingTimestamps() {
    for (int i = 0; i < this->nWorkers; ++i) {
        cout << this->feedingTimestamps[i] << " ";
    }

    cout << endl;
}