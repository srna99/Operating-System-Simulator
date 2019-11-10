/*
 * processStructures.cpp
 *
 *  Created on: Nov 10, 2019
 *      Author: serena
 */

#include "processStructures.h"


processStructures::processStructures() {}
processStructures::~processStructures() {}

void processStructures::addToReadyQ(process process) {
	//dp.updateState(Ready, process.getPcb());
	readyQ.push(process);
}

void processStructures::addToWaitQ(process process) {

}

void processStructures::addToProcessesQ(process process) {

}



//void scheduler::addToReadyQ(program program) {
//	dp.updateState(Ready, program.getPcb());
//	readyQ.push(program);
//}
//
//program * scheduler::getFirstInReadyQ() { return &readyQ.front(); }
//
//void scheduler::yieldInReadyQ() {
//	dp.updateState(Ready, readyQ.front().getPcb());
//	readyQ.push(readyQ.front());
//	readyQ.pop();
//}
//
//void scheduler::removeFromReadyQ() {
//	dp.updateState(Exit, readyQ.front().getPcb());
//	readyQ.pop();
//}
//
//int scheduler::getReadyQSize() { return readyQ.size(); }
//
//void scheduler::addToWaitQ() {
//	dp.updateState(Wait, readyQ.front().getPcb());
//	waitQ.push(readyQ.front());
//	readyQ.pop();
//}
//
//void scheduler::removeFromWaitQ() {
//	dp.updateState(Ready, waitQ.front().getPcb());
//	readyQ.push(waitQ.front());
//	waitQ.pop();
//}
//
//int scheduler::getWaitQSize() { return waitQ.size(); }
