/*
 * pcb.cpp
 *
 *      Author: Serena Cheng
 */

#include "pcb.h"
#include <iostream>


pcb::pcb() {
//	setState(Exit);
	setRuntime(0);
	setPc(1);
}
pcb::~pcb() {}

int pcb::getProcessId() { return processId; }
void pcb::setProcessId(int number){
	processId = number;
}

State pcb::getState() { std::cout << "get " << state << std::endl; return state; }
void pcb::setState(State currentState) {
	state = currentState;
	std::cout << "pcb " << currentState << " " << state << std::endl;
}

int pcb::getRuntime() { return runtime; }
void pcb::setRuntime(int time){
	runtime = time;
}

int pcb::getPc() { return pc; }
void pcb::setPc(int address){
	pc = address;
}
