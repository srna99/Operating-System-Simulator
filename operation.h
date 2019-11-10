/*
 * operation.h
 *
 * Author: Serena Cheng
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include "process.h"

class operation {

	public:

		operation();
		virtual ~operation();

		int calculate(int cycles);
		void wait(int cycles);
		void yield();
		void out(process &process);
		void exit();
		void cycleLoop(int cycles, bool isCalc);
		int getLeftOverCycles();
		void setLeftOverCycles(int cycles);

	private:

		int leftOverCycles;

};

#endif /* OPERATION_H_ */
