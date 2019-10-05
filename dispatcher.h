/*
 * dispatcher.h
 *
 *      Author: Serena Cheng
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_

enum State { New, Running, Waiting, Ready, Terminated };

class dispatcher {

	public:

		dispatcher();
		virtual ~dispatcher();

		State updateState(State currentState);

};

#endif /* DISPATCHER_H_ */
