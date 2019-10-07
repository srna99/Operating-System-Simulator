/*
 * main.cpp
 *
 *      Author: Serena Cheng
 */

#include "programManager.h"
#include "scheduler.h"
#include <iostream>
#include <thread>

using namespace std;

void cycleLoop(int cycles) {
	cout << "inside " << cycles << endl;
	while (cycles > 0)
		cycles--;
}

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

	thread t1;

	bool firstTime = true;
	while (scheduler::instance().getReadyQSize() > 0) {

		scheduler::instance().process();

		if (scheduler::instance().getWaitQSize() > 0 && firstTime) {

			t1 = thread(cycleLoop, scheduler::instance().getFirstInWaitQ().second);

			firstTime = false;

		}

	}

	t1.join();
	cout << "done" << endl;

	return 0;

}
