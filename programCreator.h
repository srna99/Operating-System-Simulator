/*
 * programCreator.h
 *
 *      Author: Serena Cheng
 */

#ifndef PROGRAMCREATOR_H_
#define PROGRAMCREATOR_H_

#include <string>

class programCreator {

	public:

		programCreator();
		virtual ~programCreator();

		void createProgram(int programNumber, int numberToMake);

	private:

		std::string chooseFile(int number);

};

#endif /* PROGRAMCREATOR_H_ */
