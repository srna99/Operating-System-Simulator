/*
 * memoryManager.h
 *
 * Author: Serena Cheng
 */

#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

class memoryManager {

	public:

		memoryManager();
		virtual ~memoryManager();

		bool allocateMemory(int memorySize);
		void deallocateMemory(int memorySize);

	private:

		static const int CPU_MEMORY;
		static int memoryAvailable;

};

#endif /* MEMORYMANAGER_H_ */
