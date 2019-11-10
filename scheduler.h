/*
 * scheduler.h
 *
 *      Author: Serena Cheng
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "process.h"
#include "dispatcher.h"
#include <queue>

class scheduler {

	public:

		static scheduler& instance() { static scheduler sch; return sch; };
		virtual ~scheduler();

		void addToReadyQ(process program);
		process * getFirstInReadyQ();
		void yieldInReadyQ();
		void removeFromReadyQ();
		int getReadyQSize();
		void addToWaitQ();
		void removeFromWaitQ();
		int getWaitQSize();

	private:

		scheduler();
		std::queue<process> readyQ;
		std::queue<process> waitQ;
		dispatcher dp;

};

#endif /* SCHEDULER_H_ */
