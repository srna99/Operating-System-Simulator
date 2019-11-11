/*
 * mutexLock.cpp
 *
 * Author: Serena Cheng
 */

#include "mutexLock.h"


mutexLock::mutexLock() { isAvailable = true; }
mutexLock::~mutexLock() {}

bool mutexLock::acquire() {
	if (isAvailable) {
		isAvailable = !isAvailable;
		return true;
	}
	return false;
}

void mutexLock::release() {
	if (!isAvailable) {
		isAvailable = !isAvailable;
	}
}
