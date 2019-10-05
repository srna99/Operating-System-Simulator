/*
 * programTemplate.h
 *
 *      Author: Serena Cheng
 */

#ifndef PROGRAMTEMPLATE_H_
#define PROGRAMTEMPLATE_H_

#include <string>

class programTemplate {

	public:

		void openProgram(int programNumber, int numberToMake);
		programTemplate();
		~programTemplate();

	private:

		std::string chooseFile(int number);

};

#endif /* PROGRAMTEMPLATE_H_ */
