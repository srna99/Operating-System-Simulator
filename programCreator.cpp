/*
 * programCreator.cpp
 *
 *      Author: Serena Cheng
 */

#include "programCreator.h"

#include "program.h"
#include <cstring>

using namespace std;


programCreator::programCreator() {};
programCreator::~programCreator() {};

void programCreator::createProgram(int programNumber, int numberToMake) {

	string filePath = chooseFile(programNumber);

	for(int i = 0; i < numberToMake; i++) {
		program process(filePath);
	}

}

string programCreator::chooseFile(int number) {

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

