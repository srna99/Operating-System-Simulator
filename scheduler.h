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
#include <thread>
#include <queue>

class scheduler {

	public:

		static scheduler& instance() { static scheduler sch; return sch; };
		virtual ~scheduler();

		void addToReadyQ(std::thread th, bool inWaitQ);
		std::thread getFirstInReadyQ();
		void yieldInReadyQ();
		void removeFromReadyQ();
		int getReadyQSize();
		void addToWaitQ(std::thread th, bool inReadyQ);
		std::thread getFirstInWaitQ();
		void yieldInWaitQ();
		int getWaitQSize();

	private:

		scheduler();
		std::queue<std::thread> readyQ;
		std::queue<std::thread> waitQ;
		dispatcher dp;
		memoryManager mm;

};

#endif /* SCHEDULER_H_ */
