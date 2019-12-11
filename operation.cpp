/*
 * operation.cpp
 *
 * Author: Serena Cheng
 */

#include "processManager.h"
#include "operation.h"
#include "scheduler.h"
#include <iostream>

using namespace std;

//FIGURE OUT SOMETHING WITH CYCLES; WHAT TO DO WITH WAIT (THREAD?)
operation::operation() { leftOverCycles = 0; }
operation::~operation() {}

int operation::calculate(int cycles) {
	cycleLoop(cycles, true);
	if (getLeftOverCycles() > 0) { return getLeftOverCycles(); } else { return 0; }
}

void operation::wait(int cycles) {
	scheduler::instance().addToWaitQ(*scheduler::instance().getFirstInReadyQ(), true);
	cycleLoop(cycles, false);
	scheduler::instance().addToReadyQ(*scheduler::instance().getFirstInWaitQ(), true);
}

void operation::yield() {
	scheduler::instance().yieldInReadyQ();
}

string operation::out(process &process) {

	string s =  "Name: " + process.getName() +
			"\nProcess ID: " + to_string(process.getPcb()->getProcessId()) +
			"\nState: " + to_string(process.getPcb()->getState()) +
			"\nRuntime: " + to_string(process.getPcb()->getRuntime()) +
			"\nMemory: " + to_string(process.getPcb()->getMemory()) +
			"\nPC: " + to_string(process.getPcb()->getPc());

	return s;

}

void operation::exit() {
	scheduler::instance().removeFromReadyQ();
}

void operation::cycleLoop(int cycles, bool isCalc) {

	while (cycles > 0) {

		if (interruptSignal && isCalc) {
			setLeftOverCycles(cycles);
			break;
		} else if (isCalc) {
			scheduler::instance().getFirstInReadyQ()->second.getPcb()->incrementRuntime();
			updatePCB(scheduler::instance().getFirstInReadyQ()->second);
		}

		cycles--;

	}

}

int operation::getLeftOverCycles() { return leftOverCycles; }
void operation::setLeftOverCycles(int cycles) { leftOverCycles = cycles; }
