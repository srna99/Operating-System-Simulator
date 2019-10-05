/*
 * programManager.h
 *
 *      Author: Serena Cheng
 */

#ifndef PROGRAMMANAGER_H_
#define PROGRAMMANAGER_H_

#include "program.h"
#include <string>
#include <map>

class programManager {

	public:

		programManager();
		virtual ~programManager();

		void createProgram(int programNumber, int numberToMake);

	private:

		std::map<int, std::string> processes;
		std::string chooseFile(int number);

};

#endif /* PROGRAMMANAGER_H_ */
