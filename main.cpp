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

	const int ROUND_ROBIN_CYCLES = 50;
	interruptSignal = false;

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
	int counter = processes.size();

	while (counter > 0) {

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
//		cout << "rq " << scheduler::instance().getReadyQSize() << endl;
//		cout << "wq " << scheduler::instance().getWaitQSize() << endl;
		if (scheduler::instance().getReadyQSize() > 0 || scheduler::instance().getWaitQSize() > 0) {

			interruptSignal = false;

			int currentCycle = 1;
			while (currentCycle <= ROUND_ROBIN_CYCLES && !interruptSignal) {	//thread here?

				if (scheduler::instance().getFirstInReadyQ()->getPcb()->getState() == 4) { break; }

				pm.openProcess(scheduler::instance().getFirstInReadyQ());

				currentCycle++;
				//cout << currentCycle << endl;
			}

			if (!interruptSignal) { interruptSignal = true; }

		}

//		while (scheduler::instance().getReadyQSize() > 0) {
//			pm.openProcess(scheduler::instance().getFirstInReadyQ());
//		}

	}

	return 0;

}
