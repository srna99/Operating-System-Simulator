/*
 * scheduler.cpp
 *
 *      Author: Serena Cheng
 */

#include "scheduler.h"

using namespace std;


scheduler::scheduler(vector<program> processes) { initializeReadyQueue(processes); }
scheduler::~scheduler() {}

void scheduler::initializeReadyQueue(vector<program> processes) {

	for(int i = 0; i < processes.size(); i++) {

		dp.updateState(Ready, processes[i].getPcb());
		readyQ.push(processes[i]);

	}

}
