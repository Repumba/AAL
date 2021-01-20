#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#include "../include/cli.h"


using namespace std;

UserInterface::UserInterface(int argc, char ** argv) {

    // std::cout << "Argv_1: " << argv[1] << std::endl;
    // std::cout << "Argv_2: " << argv[2] << std::endl;

    if (std::string(argv[1]) == "-m") {

        std::cout << "I'm here" << std::endl;
        setMode(std::string(argv[2]));  

    } else {
        setMode(std::string("manual"));
    }
    
    parseCommands(argc, argv);
}


void UserInterface::setMode(const std::string&& sMode) {

    
    if (sMode == "manual") {
        this->mode = MANUAL;
    } else if (sMode == "auto") {
        this->mode = AUTO;
    } else if (sMode == "time_test") {
        this->mode = TIME_TEST;
    }
}


// ONLY IN TIME_TEST MODE
void UserInterface::setDistribution(const std::string&& sDistr) {
    if (sDistr == "poisson") {
        this->distribution = POISSON;
    } else {
        this->distribution = UNIFORM;
    }
}

void UserInterface::parseCommands(int argc, char ** argv) {

    auto mode = this->getMode();

    if (mode == AUTO) {
        
        for (int i = 3; i < argc; ++i) {

            auto cmd = std::string(argv[i]);

            try {
                
                if (cmd == "-n" && ++i < argc) {
                    this->nWorkers = std::atoi(argv[i]);
                    this->comingTimestamps = new int[this->nWorkers];
                } else if (cmd == "-c" && ++i < argc) {
                    this->capacity = std::atoi(argv[i]);
                } else if (cmd == "-t" && ++i < argc) {
                    this->unitTimeCooking = std::atoi(argv[i]);
                } else if (cmd == "-d" && ++i < argc) {
                    setDistribution(argv[i]);
                } else if (cmd == "-w" && ++i < argc) {
                    for (int j = 0; j < this->nWorkers; j++) {
                        this->comingTimestamps[j] = std::atoi(argv[i++]);
                        std::cout << "Moment: " << this->comingTimestamps[j] << std::endl;
                    }
                }

            } catch (std::exception e) {
                printHelp();
                exit(0);
            }
            
        }

    }  else if (mode == TIME_TEST) {

        int nWorkers, mCap, tCook;
        char distrType;
        
        int * comingTimestamps;

        std::string filename = "";
        if (std::string(argv[3]) == "-f") {
            filename = std::string(argv[4]);
        }

        std::cout << "Filename: " << filename << std::endl;
        // instance of problem from file
        std::ifstream inputStream(filename);
        
        // TODO:change it for exception handling later
        if (!inputStream) {
            std::cout << "Can't open input file" << std::endl;
            exit(-1);
        }

        inputStream >> nWorkers >> mCap >> tCook >> distrType;
        comingTimestamps = new int[nWorkers];
        
        for (int i = 0; i < nWorkers; i++) {
            inputStream >> comingTimestamps[i];
        }

        inputStream.close();

        this->setCapacity(mCap);
        this->setWorkers(nWorkers);
        this->setUnitTimeCooking(tCook);
        this->setComingTimestamps(comingTimestamps);
        
    } else {
        this->acquireData();
    }
}


void UserInterface::acquireData() {

    /*
        A method to get data from user (ONLY MANUAL MODE);
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

UserInterface::Mode UserInterface::getMode() const {
    return this->mode;
}

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

void UserInterface::setWorkers(int workers) {
    this->nWorkers = workers;
}

void UserInterface::setCapacity(int capacity) {
    this->capacity = capacity;
}

void UserInterface::setUnitTimeCooking(int tCook) {
    this->unitTimeCooking = tCook;
}

void UserInterface::setComingTimestamps(int * comingTimestamps) {
    this->comingTimestamps = comingTimestamps;
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



// TODO: Create a better printHelp
void UserInterface::printHelp() const {
    cout << "Hello World\nInvalid usage of parameters" << endl;
}