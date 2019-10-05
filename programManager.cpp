/*
 * programManager.cpp
 *
 *      Author: Serena Cheng
 */

#include "programManager.h"

using namespace std;


programManager::programManager() {};
programManager::~programManager() {};

void programManager::createProgram(int programNumber, int numberToMake) {

	string filePath = chooseFile(programNumber);

	for(int i = 0; i < numberToMake; i++) {
		program process();

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

