/*
 * scheduler.h
 *
 *      Author: Serena Cheng
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "process.h"
#include "dispatcher.h"
#include "memoryManager.h"
#include <queue>

class scheduler {

	public:

		static scheduler& instance() { static scheduler sch; return sch; };
		virtual ~scheduler();

		bool addToReadyQ(process program, bool inWaitQ);
		process * getFirstInReadyQ();
		void yieldInReadyQ();
		void removeFromReadyQ();
		int getReadyQSize();
		void addToWaitQ(process process, bool inReadyQ);
		process * getFirstInWaitQ();
		int getWaitQSize();

	private:

		scheduler();
		std::queue<process> readyQ;
		std::queue<process> waitQ;
		dispatcher dp;
		memoryManager mm;

};

#endif /* SCHEDULER_H_ */
