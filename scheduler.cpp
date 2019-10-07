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
		readyQ.push(make_pair(processes[i], 0));

	}

}

void scheduler::process() {
	pm.openProgram(readyQ.front().first);
}

pair<program, int> scheduler::getFirstInReadyQ() { return readyQ.front(); }

void scheduler::yieldInReadyQ() {
	dp.updateState(Ready, readyQ.front().first.getPcb());
	readyQ.push(readyQ.front());
	readyQ.pop();
}

void scheduler::removeFromReadyQ() {
	dp.updateState(Exit, readyQ.front().first.getPcb());
	readyQ.pop();
}

int scheduler::getReadyQSize() { return readyQ.size(); }

pair<program, int> scheduler::getFirstInWaitQ() { return waitQ.front(); }

void scheduler::addToWaitQ() {
	dp.updateState(Wait, readyQ.front().first.getPcb());
	waitQ.push(readyQ.front());
	readyQ.pop();
}

void scheduler::removeFromWaitQ() {
	dp.updateState(Ready, waitQ.front().first.getPcb());
	readyQ.push(waitQ.front());
	waitQ.pop();
}

int scheduler::getWaitQSize() { return waitQ.size(); }

void scheduler::updateCycles(int cycles) {
	readyQ.front().second = cycles;
}
