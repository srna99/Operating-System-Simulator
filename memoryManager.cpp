/*
 * memoryManager.cpp
 *
 * Author: Serena Cheng
 */

#include "memoryManager.h"


const int memoryManager::CPU_MEMORY = 150;
int memoryManager::memoryAvailable = CPU_MEMORY;

memoryManager::memoryManager() {}
memoryManager::~memoryManager() {}

bool memoryManager::allocateMemory(program process) {

	if (process.getPcb()->getMemory() <= memoryAvailable) {
		memoryAvailable -= process.getPcb()->getMemory();
		return true;
	}

	return false;
}

void memoryManager::deallocateMemory() {

}
