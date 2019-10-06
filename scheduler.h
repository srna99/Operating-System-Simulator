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
#include <queue>

class scheduler {

	public:

		static scheduler& instance() { static scheduler sch; return sch; };
		virtual ~scheduler();

		void initializeReadyQueue(std::vector<program> processes);
		void process();
		void yieldInReadyQ();
		void removeFromReadyQ();
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
