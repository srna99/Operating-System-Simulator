/*
 * operation.cpp
 *
 *      Author: Serena Cheng
 */

#include "operation.h"
#include "scheduler.h"
#include <iostream>

using namespace std;


operation::operation() {}
operation::~operation() {}

void operation::calculate(int cycles) {

	cout << "c" << endl;

}

void operation::wait(int cycles) {

	cout << "w" << endl;

	scheduler::instance().updateCycles(cycles);
	scheduler::instance().addToWaitQ();

}

void operation::yield() {

	cout << "y" << endl;

	scheduler::instance().yieldInReadyQ();

}

void operation::out(program process) {

	cout << "o" << endl;

	cout << "Name: " << process.getName() << endl;
	cout << "Process ID: " << process.getPcb()->getProcessId() << endl;
	cout << "State: " << process.getPcb()->getState() << endl;
	cout << "Runtime: " << process.getPcb()->getRuntime() << endl;
	cout << "PC: " << process.getPcb()->getPc() << endl;

}

void operation::exit() {
	scheduler::instance().removeFromReadyQ();
}
