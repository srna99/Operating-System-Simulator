/*
 * program.cpp
 *
 *      Author: Serena Cheng
 */

#include "program.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;


int program::idCounter = 1;
string filePath;

program::program(string path) {

	pcb currentPcb(idCounter++);
	filePath = path;

}

program::~program() {}

void program::openProgram(string filePath) {

	ifstream inFile;

	inFile.open(filePath);

	if (!inFile) {

		cout << "Unable to open file";
		exit(1);

	} else {

	}

	inFile.close();

}
