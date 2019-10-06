/*
 * programManager.h
 *
 *      Author: Serena Cheng
 */

#ifndef PROGRAMMANAGER_H_
#define PROGRAMMANAGER_H_

#include "program.h"
#include "dispatcher.h"
#include <string>
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
		std::string chooseFile(int number);

};

#endif /* PROGRAMMANAGER_H_ */
