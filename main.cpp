/*
 * main.cpp
 *
 * Author: Serena Cheng
 */

#include "programManager.h"
#include "scheduler.h"
#include <iostream>

using namespace std;

int main() {

	programManager pm;
	memoryManager mm;

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
	int size = processes.size();

	while (processes.size() > 0) {

		vector<program>::iterator it;
		int counter = 0;
		for(it = processes.begin(); it != processes.end(); it++, counter++) {

			if (counter < size) {

				if(mm.allocateMemory(it->getPcb()->getMemory())) {
					scheduler::instance().addToReadyQ(*it);
					processes.erase(processes.begin());
				} else {
					processes.push_back(*it);
					processes.erase(processes.begin());
				}

			} else break;

		}

		while (scheduler::instance().getReadyQSize() > 0) {
			pm.openProgram(scheduler::instance().getFirstInReadyQ());
		}

	}

	return 0;

}
