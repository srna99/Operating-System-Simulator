/*
 * programManager.cpp
 *
 *      Author: Serena Cheng
 */

#include "programManager.h"
#include <fstream>
#include <iostream>

using namespace std;


programManager::programManager() {}
programManager::~programManager() {}

vector<program> programManager::getProcesses() {
	processes.shrink_to_fit();
	return processes;
}

void programManager::createProgram(int programNumber, int numberToMake) {

	string filePath = chooseFile(programNumber);

	for(int i = 0; i < numberToMake; i++) {

		program process(filePath);
		dp.updateState(New, process.getPcb());

		processes.push_back(process);
		cout << "pm " << process.getPcb().getState() << endl;
	}

}

string programManager::chooseFile(int number) {

	string filePath = "template files/program_file";

	switch(number) {

	case 1:
		return filePath + "1.txt";
	case 2:
		return filePath + "2.txt";
	case 3:
		return filePath + "3.txt";
	case 4:
		return filePath + "4.txt";
	default:
		break;

	}

	return "";

}

void programManager::openProgram(program process) {

	ifstream inFile;

	inFile.open(process.getFilePath());

	if (!inFile) {

		cout << "Unable to open file.";
		exit(1);

	} else {

	}

	inFile.close();

}
