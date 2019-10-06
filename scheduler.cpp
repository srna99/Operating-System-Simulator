/*
 * scheduler.cpp
 *
 *      Author: Serena Cheng
 */

#include "scheduler.h"
#include <iostream>

using namespace std;


scheduler::scheduler() {}
scheduler::~scheduler() {}

void scheduler::initializeReadyQueue(vector<program> processes) {

	for(int i = 0; i < processes.size(); i++) {

		dp.updateState(Ready, processes[i].getPcb());
		readyQ.push(processes[i]);

	}

}

//void scheduler::beginProcessing() {
//	while (readyQ.size() > 0) {
//		pm.openProgram(readyQ.front());
//	}
//}

void scheduler::yieldInReadyQ() {
	dp.updateState(Ready, readyQ.front().getPcb());
	readyQ.push(readyQ.front());
	readyQ.pop();
}

void scheduler::addToWaitQ() {
	dp.updateState(Wait, readyQ.front().getPcb());
	waitQ.push(readyQ.front());
}

void scheduler::removeFromWaitQ() {
	dp.updateState(Ready, waitQ.front().getPcb());
	readyQ.push(waitQ.front());
	waitQ.pop();
}
