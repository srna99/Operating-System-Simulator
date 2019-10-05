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

		program();
		program(std::string path);
		virtual ~program();

		pcb getPcb();
		std::string getFilePath();
		void setFilePath(std::string path);

	private:

		static int idCounter;
		pcb currentPcb;
		std::string filePath;

};

#endif /* PROGRAM_H_ */
