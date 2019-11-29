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
#include "mutexLock.h"
#include <vector>

extern bool interruptSignal;

class processManager {

	public:

		processManager();
		virtual ~processManager();

		std::vector<process> getProcesses();
		void createProcess(int programNumber, int numberToMake);
		void setMemory(process &process);
		void openProcess(process &process);
//		void print(process &p);
//		void start(process process);
//		void *openProcess(void *process);

	private:

		std::vector<process> processes;
		dispatcher dp;
		int idCount;
		operation op;
		mutexLock lock;
		bool signalActive;
		std::pair<std::string, std::string> chooseFile(int number);
		std::ifstream * goToLine(std::ifstream *inFile, int lineNumber, process &process);
		void readFile(std::ifstream *inFile, process &process);
		void execute(std::string line, process &process);
		int generateRandomNumber();

};

#endif /* PROCESSMANAGER_H_ */
