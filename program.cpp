/*
 * program.cpp
 *
 *      Author: Serena Cheng
 */

#include "program.h"
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;


int program::idCounter = 1;

program::program() {
	currentPcb.setProcessId(idCounter++);
}

program::~program() {}

int program::getProcessId() {
	return currentPcb.getProcessId();
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
