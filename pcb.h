/*
 * pcb.h
 *
 *      Author: Serena Cheng
 */

#ifndef PCB_H_
#define PCB_H_

enum State { New, Ready, Run, Wait, Exit };

class pcb {

	public:

		pcb();
		virtual ~pcb();

		int getProcessId();
		void setProcessId(int number);
		State getState();
		void setState(State currentState);
		int getRuntime();
		void setRuntime(int time);
		int getPc();
		void setPc(int line);

	private:

		int processId;
		State state;
		int runtime;
		int pc;

};

#endif /* PCB_H_ */
