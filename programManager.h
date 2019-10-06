/*
 * programManager.h
 *
 *      Author: Serena Cheng
 */

#ifndef PROGRAMMANAGER_H_
#define PROGRAMMANAGER_H_

#include "program.h"
#include "dispatcher.h"
#include "operation.h"
#include <vector>

class programManager {

	public:

		programManager();
		virtual ~programManager();

		std::vector<program> getProcesses();
		void createProgram(int programNumber, int numberToMake);
		void openProgram(program process);

	private:

		std::vector<program> processes;
		dispatcher dp;
		operation op;
		std::pair<std::string, std::string> chooseFile(int number);
		std::ifstream * goToLine(std::ifstream *inFile, int lineNumber, program process);
		void readFile(std::ifstream *inFile, program process);

};

#endif /* PROGRAMMANAGER_H_ */
