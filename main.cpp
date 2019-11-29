/*
 * main.cpp
 *
 * Author: Serena Cheng
 */

#include "processManager.h"
#include "scheduler.h"
#include "memoryManager.h"
#include <iostream>
#include <thread>

using namespace std;


int main() {

	processManager pm;
	memoryManager mm;

	const int ROUND_ROBIN_CYCLES = 50;
	interruptSignal = false;

	int num, sum = 0;

	cout << "How many text processors do you want to run?" << endl;
	cin >> num;
	pm.createProcess(1, num);
	sum += num;

	cout << "How many web browsers do you want to run?" << endl;
	cin >> num;
	pm.createProcess(2, num);
	sum += num;

	cout << "How many photo editors do you want to run?" << endl;
	cin >> num;
	pm.createProcess(3, num);
	sum += num;

	cout << "How many music players do you want to run?" << endl;
	cin >> num;
	pm.createProcess(4, num);
	sum += num;

	vector<thread> threads;

	vector<process> processes = pm.getProcesses();

//	vector<process>::iterator it;
//	for(it = processes.begin(); it != processes.end(); it++) {
	for (process &p : processes) {

//		thread th(&processManager::open);
//		th.join();

//		if(!scheduler::instance().addToReadyQ(*it, false)) {
//			scheduler::instance().addToWaitQ(*it, false);
//		}
//		process p = *it;
		pm.setMemory(p);

		thread th(&processManager::openProcess, &pm, ref(p));
		threads.push_back(move(th));

		if (mm.allocateMemory(p.getPcb()->getMemory())) {
			scheduler::instance().addToReadyQ(move(th), false);
		} else {
			scheduler::instance().addToWaitQ(move(th), false);
		}

	}

	int counter, size;

	while (scheduler::instance().getReadyQSize() > 0 || scheduler::instance().getWaitQSize() > 0) {

		interruptSignal = false;

//		pm.start(scheduler::instance().getFirstInReadyQ());
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

//	vector<thread>::iterator iter;
//	for(iter = threads.begin(); iter != threads.end(); iter++) {
	for (thread &th : threads) {
		if (th.joinable()){
			th.join();
		}
	}

	threads.clear();
	processes.clear();

	return 0;

}
