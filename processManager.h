/*
 * processManager.h
 *
 * Author: Serena Cheng
 */

#ifndef PROCESSMANAGER_H_
#define PROCESSMANAGER_H_

#include "process.h"
#include "dispatcher.h"
#include "operation.h"
#include <vector>

extern bool interruptSignal;

class processManager {

	public:

		processManager();
		virtual ~processManager();

		std::vector<process> getProcesses();
		void createProcess(int programNumber, int numberToMake);
		void openProcess(process *process);

	private:

		std::vector<process> processes;
		dispatcher dp;
		operation op;
		std::pair<std::string, std::string> chooseFile(int number);
		std::ifstream * goToLine(std::ifstream *inFile, int lineNumber, process &process);
		void readFile(std::ifstream *inFile, process &process);
		int generateRandomNumber();

};

#endif /* PROCESSMANAGER_H_ */
