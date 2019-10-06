/*
 * dispatcher.h
 *
 *      Author: Serena Cheng
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#include "pcb.h"

class dispatcher {

	public:

		dispatcher();
		virtual ~dispatcher();

		void updateState(State currentState, pcb *currentPcb);

};

#endif /* DISPATCHER_H_ */
