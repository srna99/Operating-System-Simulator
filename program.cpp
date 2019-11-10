/*
 * program.cpp
 *
 * Author: Serena Cheng
 */

#include "program.h"

using namespace std;


int program::idCounter = 0;

program::program(string name, string path) {

	incrementIdCounter();
	currentPcb.setMemory(0);

	setName(name);
	setFilePath(path);

}
program::~program() {}

pcb * program::getPcb() { return &currentPcb; }

string program::getName() { return name; }
void program::setName(string fileName) {
	name = fileName;
}

string program::getFilePath() { return filePath; }
void program::setFilePath(string path) {
	filePath = path;
}

void program::incrementIdCounter() {
	idCounter++;
	currentPcb.setProcessId(idCounter);
}
