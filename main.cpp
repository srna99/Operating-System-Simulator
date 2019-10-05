/*
 * main.cpp
 *
 *      Author: Serena Cheng
 */

#include <iostream>
#include "programCreator.h"

using namespace std;

int main() {

	programCreator program;

	int num;

	cout << "How many text processors do you want to run?" << endl;
	cin >> num;
	program.createProgram(1, num);

	cout << "How many web browsers do you want to run?" << endl;
	cin >> num;
	program.createProgram(2, num);

	cout << "How many photo editors do you want to run?" << endl;
	cin >> num;
	program.createProgram(3, num);

	cout << "How many music players do you want to run?" << endl;
	cin >> num;
	program.createProgram(4, num);


	return 0;

}
