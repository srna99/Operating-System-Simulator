/*
 * main.cpp
 *
 *      Author: Serena Cheng
 */

#include "programManager.h"
#include "scheduler.h"
#include <iostream>

using namespace std;

int main() {

	programManager pm;

	int num;

	cout << "How many text processors do you want to run?" << endl;
	cin >> num;
	pm.createProgram(1, num);

	cout << "How many web browsers do you want to run?" << endl;
	cin >> num;
	pm.createProgram(2, num);

	cout << "How many photo editors do you want to run?" << endl;
	cin >> num;
	pm.createProgram(3, num);

	cout << "How many music players do you want to run?" << endl;
	cin >> num;
	pm.createProgram(4, num);

	vector<program> processes = pm.getProcesses();

	scheduler::instance().initializeReadyQueue(processes);

	while (scheduler::instance().getReadyQSize() > 0) {
		pm.openProgram(scheduler::instance().getFirstInReadyQ());
	}

	return 0;

}
