/*
 * program.h
 *
 * Author: Serena Cheng
 */

#ifndef PROCESS_H_
#define PROCESS_H_

#include "pcb.h"
#include <string>

class process {

	public:

		process(std::string name, std::string path);
		virtual ~process();

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

#endif /* PROCESS_H_ */
