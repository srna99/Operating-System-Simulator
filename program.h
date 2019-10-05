/*
 * program.h
  *
 *      Author: Serena Cheng
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "pcb.h"
#include <string>
#include <unordered_map>

class program {

	public:

		program();
		virtual ~program();

		int getProcessId();
		void setFilePath(std::string path);
		void openProgram(int processId);

	private:

		static int idCounter;
		pcb currentPcb;
		std::string filePath;

};

#endif /* PROGRAM_H_ */
