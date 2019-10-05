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

const static int MAX_SIZE = 100;
extern program processes[MAX_SIZE];

class programManager {

	public:

		programManager();
		virtual ~programManager();

		void createProgram(int programNumber, int numberToMake);
		void openProgram(program process);

	private:

		dispatcher dp;
		std::string chooseFile(int number);

};

#endif /* PROGRAMMANAGER_H_ */
