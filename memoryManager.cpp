/*
 * memoryManager.cpp
 *
 * Author: Serena Cheng
 */

#include "memoryManager.h"


const int memoryManager::CPU_MEMORY = 500;
int memoryManager::memoryAvailable = CPU_MEMORY;

memoryManager::memoryManager() {}
memoryManager::~memoryManager() {}

bool memoryManager::allocateMemory(int memorySize) {

	if (memorySize <= memoryAvailable) {
		memoryAvailable -= memorySize;
		return true;
	}

	return false;
}

void memoryManager::deallocateMemory(int memorySize) {
	memoryAvailable += memorySize;
}
