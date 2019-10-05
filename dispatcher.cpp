/*
 * dispatcher.cpp
 *
 *      Author: Serena Cheng
 */

#include "dispatcher.h"


dispatcher::dispatcher() {}

dispatcher::~dispatcher() {}

void dispatcher::updateState(State currentState, pcb currentPcb) {
	currentPcb.setState(currentState);
}
