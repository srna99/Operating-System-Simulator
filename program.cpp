/*
 * program.cpp
 *
 *      Author: Serena Cheng
 */

#include "program.h"
#include <fstream>
#include <iostream>

using namespace std;


int program::idCounter = 1;

program::program() {}
program::program(string path) {
	currentPcb.setProcessId(idCounter++);
	setFilePath(path);
}
program::~program() {}

pcb program::getPcb() {
	return currentPcb;
}

void program::setFilePath(string path) {
	filePath = path;
}

void program::openProgram(int processId) {

	ifstream inFile;

	inFile.open(filePath);

	if (!inFile) {

		cout << "Unable to open file.";
		exit(1);

	} else {

	}

	inFile.close();

}
