/*
 * program.h
  *
 *      Author: Serena Cheng
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "pcb.h"
#include <string>

class program {

	public:

		program(std::string path);
		virtual ~program();

		void openProgram(std::string filePath);

	private:

		static int idCounter;

};

#endif /* PROGRAM_H_ */
