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


operation::operation() { leftOverCycles = 0; }
operation::~operation() {}

int operation::calculate(int cycles) {
	cycleLoop(cycles, true);
	if (getLeftOverCycles() > 0) { return getLeftOverCycles(); } else { return 0; }
}

void operation::wait(int cycles) {
	scheduler::instance().addToWaitQ();
	cycleLoop(cycles, false);
	scheduler::instance().removeFromWaitQ();
}

void operation::yield() {
	scheduler::instance().yieldInReadyQ();
}

void operation::out(process &process) {

	cout << endl;
	cout << "Name: " << process.getName() << endl;
	cout << "Process ID: " << process.getPcb()->getProcessId() << endl;
	cout << "State: " << process.getPcb()->getState() << endl;
	cout << "Runtime: " << process.getPcb()->getRuntime() << endl;
	cout << "Memory: " << process.getPcb()->getMemory() << endl;
	cout << "PC: " << process.getPcb()->getPc() << endl;

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
			scheduler::instance().getFirstInReadyQ()->getPcb()->incrementRuntime();
		}

		cycles--;

	}

}

int operation::getLeftOverCycles() { return leftOverCycles; }
void operation::setLeftOverCycles(int cycles) { leftOverCycles = cycles; }
