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
		std::pair<program, int> getFirstInReadyQ();
		void yieldInReadyQ();
		void removeFromReadyQ();
		int getReadyQSize();
		std::pair<program, int> getFirstInWaitQ();
		void addToWaitQ();
		void removeFromWaitQ();
		int getWaitQSize();
		void updateCycles(int cycles);

	private:

		scheduler();
		std::queue< std::pair<program, int> > readyQ;
		std::queue< std::pair<program, int> > waitQ;
		dispatcher dp;
		programManager pm;

};

#endif /* SCHEDULER_H_ */
