#include <iostream>
#include <fstream>
#include <cstring>

#include "include/cli.h"
#include "include/mainAlgorithm.h"
#include "include/MeasureTime.h"


int main(int argc, char* argv[]) {


    // std::cout << "Argv_1: " << argv[1] << std::endl;
    // std::cout << "Argv_2: " << argv[2] << std::endl;

    UserInterface * cli = new UserInterface(argc, argv);
    MeasureTime * mt = new MeasureTime();
    int nWorkers, mCap, tCook;
    char distrType;
    
    int * comingTimestamps;

    auto mode = cli->getMode();

    mt->startClock();

    Solver * solver = new Solver(
        cli->getWorkers(),
        cli->getCapacity(),
        cli->getUnitTimeCooking(),
        cli->getComingTimetamps()
    );

    solver->optimize();
    cli->setFeedingTimestamps(solver->getFeedingTimestamps());
    cli->setTotalTimeWait(solver->getTotalWaitingTime());

    mt->stopClock();
    
    cli->printTotalTimeWait();
    cli->printFeedingTimestamps();

    if (mode == UserInterface::TIME_TEST) {
        std::cout << mt->getTimeMilli() << " ms" << std::endl;
        std::cout << mt->getTimeMicro() << " us" << std::endl;
        std::cout << mt->getTimeNano() << " ns" << std::endl;
    }

}
