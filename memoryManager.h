/*
 * memoryManager.h
 *
 * Author: Serena Cheng
 */

#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include "program.h"

class memoryManager {

	public:

		memoryManager();
		virtual ~memoryManager();

		bool allocateMemory(program process);
		void deallocateMemory();

	private:

		static const int CPU_MEMORY;
		static int memoryAvailable;

};

#endif /* MEMORYMANAGER_H_ */
