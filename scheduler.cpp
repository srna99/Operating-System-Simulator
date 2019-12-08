/*
 * scheduler.cpp
 *
 * Author: Serena Cheng
 */

#include "processManager.h"
#include "scheduler.h"
#include <iostream>

using namespace std;


scheduler::scheduler() {}
scheduler::~scheduler() {}

void scheduler::addToReadyQ(pair<thread, process> &pair, bool inWaitQ) {
	lock_guard<mutex> guard(mx);
	dp.updateState(Ready, pair.second.getPcb());
	readyQ.push(move(pair));

	if (inWaitQ) { waitQ.pop(); }
}

pair<thread, process> * scheduler::getFirstInReadyQ() { return &readyQ.front(); }

void scheduler::yieldInReadyQ() {
	lock_guard<mutex> guard(mx);
	dp.updateState(Ready, readyQ.front().second.getPcb());
	readyQ.push(move(readyQ.front()));
	readyQ.pop();
	interruptSignal = true;
}

void scheduler::removeFromReadyQ() {
	lock_guard<mutex> guard(mx);
	dp.updateState(Exit, readyQ.front().second.getPcb());
	mm.deallocateMemory(readyQ.front().second.getPcb()->getMemory());
	readyQ.pop();
	interruptSignal = true;
}

int scheduler::getReadyQSize() { return readyQ.size(); }

void scheduler::addToWaitQ(pair<thread, process> &pair, bool inReadyQ) {
	lock_guard<mutex> guard(mx);
	dp.updateState(Wait, readyQ.front().second.getPcb());
	waitQ.push(move(pair));

	if (inReadyQ) { readyQ.pop(); }

	interruptSignal = true;
}

pair<thread, process> * scheduler::getFirstInWaitQ() { return &waitQ.front(); }

void scheduler::yieldInWaitQ() {
	lock_guard<mutex> guard(mx);
	dp.updateState(Wait, waitQ.front().second.getPcb());
	waitQ.push(move(waitQ.front()));
	waitQ.pop();
}

int scheduler::getWaitQSize() { return waitQ.size(); }
