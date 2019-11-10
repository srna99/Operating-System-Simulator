/*
 * program.h
 *
 * Author: Serena Cheng
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "pcb.h"
#include <string>

class program {

	public:

		program(std::string name, std::string path);
		virtual ~program();

		pcb * getPcb();
		std::string getName();
		void setName(std::string fileName);
		std::string getFilePath();
		void setFilePath(std::string path);

	private:

		pcb currentPcb;
		std::string filePath;
		std::string name;
		static int idCounter;
		void incrementIdCounter();

};

#endif /* PROGRAM_H_ */
