/*
 * pcb.cpp
 *
 * Author: Serena Cheng
 */

#include "pcb.h"


pcb::pcb() {
	setRuntime(0);
	setCyclesLeft(0);
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

int pcb::getCyclesLeft() { return cyclesLeft; }
void pcb::setCyclesLeft(int cycles) { cyclesLeft = cycles; }

int pcb::getMemory() { return memory; }
void pcb::setMemory(int memorySize) { memory = memorySize; }

int pcb::getPc() { return pc; }
void pcb::setPc(int line) { pc = line; }
void pcb::decrementPc() { pc--; }
