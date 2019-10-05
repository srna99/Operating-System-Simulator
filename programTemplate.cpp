/*
 * programTemplate.cpp
 *
 *      Author: Serena Cheng
 */

#include "programTemplate.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;


programTemplate::programTemplate() {};
programTemplate::~programTemplate() {};

void programTemplate::openProgram(int programNumber, int numberToMake) {

	ifstream infile;
	string name = chooseFile(programNumber);

	for(int i = 0; i < numberToMake; i++) {

		infile.clear();
		infile.open(name);

		if (!infile) {
			cout << "Unable to open file";
			exit(1);
		} else
			cout << "Here" << endl;

		infile.close();

	}

}

string programTemplate::chooseFile(int number) {

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

