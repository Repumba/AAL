#include <iostream>

#include "cli.h"
#include "mainAlgorithm.h"


int main() {

    UserInterface * cli = new UserInterface();
    cli->acquireData();
    
    Solver * solver = new Solver(
        cli->getWorkers(),
        cli->getCapacity(),
        cli->getUnitTimeCooking(),
        cli->getComingTimetamps()
    );

    solver->optimize();
    cli->setFeedingTimestamps(solver->getFeedingTimestamps());
    cli->setTotalTimeWait(solver->getTotalWaitingTime());

    cli->printTotalTimeWait();
    cli->printFeedingTimestamps();

}