/*
 * program.cpp
 *
 *      Author: Serena Cheng
 */

#include "program.h"
#include <fstream>

using namespace std;


int program::idCounter = 1;

program::program(string path) {
	currentPcb.setProcessId(idCounter++);
	setFilePath(path);
}
program::~program() {}

pcb * program::getPcb() { return &currentPcb; }

string program::getFilePath() { return filePath; }
void program::setFilePath(string path) {
	filePath = path;
}
