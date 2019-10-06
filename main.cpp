/*
 * main.cpp
 *
 *      Author: Serena Cheng
 */

#include "scheduler.h"
#include <iostream>

using namespace std;

int main() {

	programManager manager;

	int num;

	cout << "How many text processors do you want to run?" << endl;
	cin >> num;
	manager.createProgram(1, num);

	cout << "How many web browsers do you want to run?" << endl;
	cin >> num;
	manager.createProgram(2, num);

	cout << "How many photo editors do you want to run?" << endl;
	cin >> num;
	manager.createProgram(3, num);

	cout << "How many music players do you want to run?" << endl;
	cin >> num;
	manager.createProgram(4, num);

	vector<program> processes = manager.getProcesses();

	scheduler sch(processes);

	return 0;

}
