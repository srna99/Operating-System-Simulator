/*
 * main.cpp
 *
 * Author: Serena Cheng
 */

#include "processManager.h"
#include "scheduler.h"
#include "memoryManager.h"
#include <iostream>

using namespace std;

int main() {

	processManager pm;
	memoryManager mm;

	int num;

	cout << "How many text processors do you want to run?" << endl;
	cin >> num;
	pm.createProcess(1, num);

	cout << "How many web browsers do you want to run?" << endl;
	cin >> num;
	pm.createProcess(2, num);

	cout << "How many photo editors do you want to run?" << endl;
	cin >> num;
	pm.createProcess(3, num);

	cout << "How many music players do you want to run?" << endl;
	cin >> num;
	pm.createProcess(4, num);

	vector<process> processes = pm.getProcesses();

	while (processes.size() > 0) {

		vector<process>::iterator it;

		for(it = processes.begin(); it != processes.end(); it++) {

			if(mm.allocateMemory(it->getPcb()->getMemory())) {
				scheduler::instance().addToReadyQ(*it);
				processes.erase(processes.begin());
			} else {
				break;
//				processes.push_back(*it);
//				processes.erase(processes.begin());
			}

		}

		if (scheduler::instance().getReadyQSize() > 0 && scheduler::instance().getWaitQSize() > 0) {

			while (true) {

			}

		}

//		while (scheduler::instance().getReadyQSize() > 0) {
//			pm.openProgram(scheduler::instance().getFirstInReadyQ());
//		}

	}

	return 0;

}
