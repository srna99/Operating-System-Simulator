/*
 * programTemplate.cpp
 *
 *      Author: Serena Cheng
 */

#include "programTemplate.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void programTemplate::openProgram(int programNumber, int numberToMake) {

	ifstream infile;
	string name = chooseFile(programNumber);

	for(int i = 0; i < numberToMake; i++) {

		infile.clear();
		infile.open(name);
		cout << "Here" << endl;
		infile.close();

	}

}

programTemplate::programTemplate() {};
programTemplate::~programTemplate() {};

string programTemplate::chooseFile(int number) {

	switch(number) {

	case 1:
		return "program_file1.txt";
	case 2:
		return "program_file2.txt";
	case 3:
		return "program_file3.txt";
	case 4:
		return "program_file1.txt";
	default:
		break;

	}

	return "";

}

