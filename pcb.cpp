/*
 * pcb.cpp
 *
 *      Author: Serena Cheng
 */

#include "pcb.h"
#include <cstring>

using namespace std;


int processId;
State state;
int runtime;
int *pc;

dispatcher dp;

pcb::pcb(int processId, int *pc) {

	setProcessId(processId);
	setState(New);
	setRuntime(0);
	setPc(pc);

}

pcb::~pcb() {}

int pcb::getProcessId() { return processId; }
void pcb::setProcessId(int number){
	processId = number;
}

State pcb::getState() { return state; }
void pcb::setState(State currentState) {
	state = dp.updateState(currentState);
}

int pcb::getRuntime() { return runtime; }
void pcb::setRuntime(int time){
	runtime = time;
}

int * pcb::getPc() { return pc; }
void pcb::setPc(int *address){
	pc = address;
}
