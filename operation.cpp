/*
 * operation.cpp
 *
 * Author: Serena Cheng
 */

#include "operation.h"
#include "scheduler.h"
#include <iostream>

using namespace std;


operation::operation() {}
operation::~operation() {}

void operation::calculate(int cycles) {

//	cout << "c" << endl;
//	cout << "run " << scheduler::instance().getFirstInReadyQ()->getPcb()->getRuntime() << endl;
	cycleLoop(cycles, true);


}

void operation::wait(int cycles) {

//	cout << "w" << endl;

	scheduler::instance().addToWaitQ();
	cycleLoop(cycles, false);
	scheduler::instance().removeFromWaitQ();

}

void operation::yield() {

//	cout << "y" << endl;

	scheduler::instance().yieldInReadyQ();

}

void operation::out(program &process) {

//	cout << "o" << endl;

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

		cycles--;

		if (isCalc) {
			scheduler::instance().getFirstInReadyQ()->getPcb()->incrementRuntime();
		}

	}
//	cout << "inside " << scheduler::instance().getFirstInReadyQ()->getPcb()->getRuntime() << endl;
}
