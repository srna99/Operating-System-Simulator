/*
 * main.cpp
 *
 *      Author: Serena Cheng
 */

#include <iostream>
#include "programManager.h"

using namespace std;

int main() {

	programManager creator;

	int num;

	cout << "How many text processors do you want to run?" << endl;
	cin >> num;
	creator.createProgram(1, num);

	cout << "How many web browsers do you want to run?" << endl;
	cin >> num;
	creator.createProgram(2, num);

	cout << "How many photo editors do you want to run?" << endl;
	cin >> num;
	creator.createProgram(3, num);

	cout << "How many music players do you want to run?" << endl;
	cin >> num;
	creator.createProgram(4, num);


	return 0;

}
