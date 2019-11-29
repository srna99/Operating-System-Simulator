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

	vector<thread> threads;

	vector<process> processes = pm.getProcesses();

	for (process &p : processes) {

		pm.setMemory(p);

		thread th(&processManager::openProcess, &pm, ref(p), true);

		pair<thread, process> pair = make_pair(move(th), p);

		if (mm.allocateMemory(p.getPcb()->getMemory())) {
			scheduler::instance().addToReadyQ(pair, false);
		} else {
			scheduler::instance().addToWaitQ(pair, false);
		}

		threads.push_back(move(th));

	}

	int counter, size;

	while (scheduler::instance().getReadyQSize() > 0 || scheduler::instance().getWaitQSize() > 0) {

		interruptSignal = false;

		int currentCycle = 1;
		while (currentCycle <= ROUND_ROBIN_CYCLES && !interruptSignal) {
			scheduler::instance().getFirstInReadyQ();
			currentCycle++;
		}

		if (!interruptSignal) { interruptSignal = true; }

		counter = 0;
		size = scheduler::instance().getWaitQSize();
		while (counter < size) {
//			if(!scheduler::instance().addToReadyQ(*scheduler::instance().getFirstInWaitQ(), true)) {
//				scheduler::instance().yieldInWaitQ();
//			}

			counter++;
		}

	}

	for (thread &th : threads) {
		if (th.joinable()){
			th.join();
		}
	}

	threads.clear();
	processes.clear();

	return 0;

}
