#include <iostream>

#include "cli.h"
#include "mainAlgorithm.h"
#include "MeasureTime.h"


int main() {

    UserInterface * cli = new UserInterface();
    MeasureTime * mt = new MeasureTime();

    cli->acquireData();
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

    std::cout << "Total time [ms]:" << mt->getTimeMilli() << std::endl;
    std::cout << "Total time [us]:" << mt->getTimeMicro() << std::endl;
    std::cout << "Total time [ns]:" << mt->getTimeNano() << std::endl;

}