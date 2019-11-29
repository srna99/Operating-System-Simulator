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
#include <condition_variable>
#include <mutex>
#include <queue>

class scheduler {

	public:

		static scheduler& instance() { static scheduler sch; return sch; };
		virtual ~scheduler();

		void addToReadyQ(std::pair<std::thread, process> &pair, bool inWaitQ);
		std::pair<std::thread, process> * getFirstInReadyQ();
		void yieldInReadyQ();
		void removeFromReadyQ();
		int getReadyQSize();
		void addToWaitQ(std::pair<std::thread, process> &pair, bool inReadyQ);
		std::pair<std::thread, process> * getFirstInWaitQ();
		void yieldInWaitQ();
		int getWaitQSize();

	private:

		scheduler();
		std::queue<std::pair<std::thread, process>> readyQ;
		std::queue<std::pair<std::thread, process>> waitQ;
		dispatcher dp;
		memoryManager mm;
		std::mutex mx;
		std::condition_variable cv;

};

#endif /* SCHEDULER_H_ */
