/*
 * main.cpp
 *
 *      Author: Serena Cheng
 */

#include "programTemplate.h"
#include <iostream>

using namespace std;

int main() {

	programTemplate program;

	int num;

	cout << "How many text processors do you want to run?" << endl;
	cin >> num;
	program.openProgram(1, num);


	return 0;

}
