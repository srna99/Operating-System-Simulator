/*
 * main.cpp
 *
 * Author: Serena Cheng
 */

#include "processManager.h"
#include "scheduler.h"
#include "memoryManager.h"
#include <iostream>
#include <pthread.h>

using namespace std;

//THREADS; CHECK IF IN WAIT CYCLE
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

	vector<process>::iterator it;
	for(it = processes.begin(); it != processes.end(); it++) {

		if(!scheduler::instance().addToReadyQ(*it, false)) {
			scheduler::instance().addToWaitQ(*it, false);
		}

	}

//	pthread_t thread;
	int counter, size;

	while (scheduler::instance().getReadyQSize() > 0 || scheduler::instance().getWaitQSize() > 0) {

		interruptSignal = false;

		//pm.start(scheduler::instance().getFirstInReadyQ());
//		process p = *scheduler::instance().getFirstInReadyQ();
//		pthread_create(&thread, NULL, (void *) pm.openProcess, (void *) p);

		int currentCycle = 1;
		while (currentCycle <= ROUND_ROBIN_CYCLES && !interruptSignal) {	//thread here?
			pm.openProcess(scheduler::instance().getFirstInReadyQ());
			currentCycle++;
		}

		if (!interruptSignal) { interruptSignal = true; }

		counter = 0;
		size = scheduler::instance().getWaitQSize();
		while (counter < size) {
			if(!scheduler::instance().addToReadyQ(*scheduler::instance().getFirstInWaitQ(), true)) {
				scheduler::instance().yieldInWaitQ();
			}

			counter++;
		}

	}
	pthread_exit(NULL);
	return 0;

}
