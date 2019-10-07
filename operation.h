/*
 * operation.h
 *
 *      Author: Serena Cheng
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include "program.h"

class operation {

	public:

		operation();
		virtual ~operation();

		void calculate(int cycles);
		void wait(int cycles);
		void yield();
		void out(program &process);
		void exit();
		void cycleLoop(int cycles, bool isCalc);

};

#endif /* OPERATION_H_ */
