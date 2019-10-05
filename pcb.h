/*
 * pcb.h
 *
 *      Author: Serena Cheng
 */

#ifndef PCB_H_
#define PCB_H_

#include "dispatcher.h"

class pcb {

	public:

		pcb(int processId, int *pc);
		virtual ~pcb();

		int getProcessId();
		void setProcessId(int number);
		State getState();
		void setState(State currentState);
		int getRuntime();
		void setRuntime(int time);
		int * getPc();
		void setPc(int *address);

	private:

		int processId;
		State state;
		int runtime;
		int *pc;

};

#endif /* PCB_H_ */
