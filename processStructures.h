/*
 * processStructures.h
 *
 *  Created on: Nov 10, 2019
 *      Author: serena
 */

#ifndef PROCESSSTRUCTURES_H_
#define PROCESSSTRUCTURES_H_

#include "process.h"
#include <queue>
#include <vector>

class processStructures {

	public:

		processStructures();
		virtual ~processStructures();

		void addToReadyQ(process process);
		void addToWaitQ(process process);
		void addToProcessesQ(process process);

	private:

		std::queue<process> processesQ;
		std::queue<process> readyQ;
		std::queue<process> waitQ;

};

#endif /* PROCESSSTRUCTURES_H_ */
