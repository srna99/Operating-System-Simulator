/*
 * dispatcher.cpp
 *
 *      Author: Serena Cheng
 */

#include "dispatcher.h"
#include <iostream>


dispatcher::dispatcher() {}
dispatcher::~dispatcher() {}

void dispatcher::updateState(State currentState, pcb currentPcb) {
	currentPcb.setState(currentState); std::cout << "dp " << currentState << std::endl;
}
