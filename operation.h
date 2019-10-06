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

		void calculate(program process, int cycles);
		void wait(program process, int cycles);
		void yield(program process);
		void out(program process);
		void exit();

};

#endif /* OPERATION_H_ */
