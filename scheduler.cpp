/*
 * scheduler.cpp
 *
 * Author: Serena Cheng
 */

#include "processManager.h"
#include "scheduler.h"
#include <iostream>

using namespace std;

//WORK ON WAIT (CYCLES, WHERE TO ADD, DONT ADD TOO EARLY, ETC.)
scheduler::scheduler() {}
scheduler::~scheduler() {}

void scheduler::addToReadyQ(thread th, bool inWaitQ) {

//	dp.updateState(Ready, process.getPcb());
	readyQ.push(th);

	if (inWaitQ) { waitQ.pop(); }


//	if (mm.allocateMemory(process.getPcb()->getMemory())) {
//
//		dp.updateState(Ready, process.getPcb());
//		readyQ.push(process);
//
//		if (inWaitQ) { waitQ.pop(); }
//
//		return true;
//
//	}
//	return false;

}

thread * scheduler::getFirstInReadyQ() { return readyQ.front(); }

void scheduler::yieldInReadyQ() {
//	dp.updateState(Ready, readyQ.front().getPcb());
	readyQ.push(readyQ.front());
	readyQ.pop();
	interruptSignal = true;
}

void scheduler::removeFromReadyQ() {
	getFirstInReadyQ().join();
//	dp.updateState(Exit, readyQ.front().getPcb());
//	mm.deallocateMemory(readyQ.front().getPcb()->getMemory());
	readyQ.pop();
	interruptSignal = true;
}

int scheduler::getReadyQSize() { return readyQ.size(); }

void scheduler::addToWaitQ(thread th, bool inReadyQ) {
//	dp.updateState(Wait, readyQ.front().getPcb());
	waitQ.push(th);

	if (inReadyQ) { readyQ.pop(); }
}

thread scheduler::getFirstInWaitQ() { return waitQ.front(); }

void scheduler::yieldInWaitQ() {
//	dp.updateState(Wait, waitQ.front().getPcb());
	waitQ.push(waitQ.front());
	waitQ.pop();
}

int scheduler::getWaitQSize() { return waitQ.size(); }
