/*
 * scheduler.h
 *
 *      Author: Serena Cheng
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "programManager.h"
#include <queue>

class scheduler {

	public:

		scheduler(std::vector<program> processes);
		virtual ~scheduler();

	private:

		std::queue<program> readyQ;
		std::queue<program> waitQ;
		dispatcher dp;
		void initializeReadyQueue(std::vector<program> processes);

};

#endif /* SCHEDULER_H_ */
