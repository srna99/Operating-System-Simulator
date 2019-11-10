/*
 * scheduler.h
 *
 *      Author: Serena Cheng
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "programManager.h"
#include "program.h"
#include "dispatcher.h"
#include "memoryManager.h"
#include <queue>

class scheduler {

	public:

		static scheduler& instance() { static scheduler sch; return sch; };
		virtual ~scheduler();

		void addToReadyQ(program program);
		program * getFirstInReadyQ();
		void yieldInReadyQ();
		void removeFromReadyQ();
		int getReadyQSize();
		void addToWaitQ();
		void removeFromWaitQ();

	private:

		scheduler();
		std::queue<program> readyQ;
		std::queue<program> waitQ;
		dispatcher dp;
		programManager pm;

};

#endif /* SCHEDULER_H_ */
