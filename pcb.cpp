/*
 * pcb.cpp
 *
 *      Author: Serena Cheng
 */

#include "pcb.h"


pcb::pcb() {
	setRuntime(0);
	setPc(1);
}
pcb::~pcb() {}

int pcb::getProcessId() { return processId; }
void pcb::setProcessId(int number) { processId = number; }

State pcb::getState() { return state; }
void pcb::setState(State currentState) { state = currentState; }

int pcb::getRuntime() { return runtime; }
void pcb::setRuntime(int time) { runtime = time; }
void pcb::incrementRuntime() { runtime++; }

int pcb::getPc() { return pc; }
void pcb::setPc(int line) { pc = line; }
