/*
 * processManager.cpp
 *
 * Author: Serena Cheng
 */

#include "processManager.h"
#include "scheduler.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <random>

using namespace std;


bool interruptSignal = false;

processManager::processManager() {
	signalActive = true;
	idCount = 0;
}
processManager::~processManager() {}

vector<process> processManager::getProcesses() {
	processes.shrink_to_fit();
	return processes;
}

void processManager::createProcess(int processNumber, int numberToMake) {

	pair<string, string> data = chooseFile(processNumber);

	for(int i = 0; i < numberToMake; i++) {

		process process(data.first, data.second);
		process.setProcessId(++idCount);
		dp.updateState(New, process.getPcb());

		processes.push_back(process);

	}

}

pair<string, string> processManager::chooseFile(int number) {

	string filePath = "template files/program_file";

	switch(number) {

	case 1:
		return make_pair("Text Processor", filePath + "1.txt");
	case 2:
		return make_pair("Web Browser", filePath + "2.txt");
	case 3:
		return make_pair("Photo Editor", filePath + "3.txt");
	case 4:
		return make_pair("Music Player", filePath + "4.txt");
	default:
		break;

	}

	return make_pair("", "");

}

void processManager::setMemory(process &process) {

	ifstream inFile;
	inFile.open(process.getFilePath());

	if (!inFile) {

		cout << "Unable to open file.";
		exit(1);

	} else {

		string line;
		while (getline(inFile, line)) {

			if (line.find("Memory") != -1) {
				string size = line.substr(line.find(" ")+1, line.length());
				int memSize = atoi(size.c_str());
				process.getPcb()->setMemory(memSize);
				break;
			}

		}

	}

	inFile.close();

}

void processManager::openProcess(process &process) {

	while (true) {

		if (this_thread::get_id() == scheduler::instance().getFirstInReadyQ()->first.get_id()
				&& scheduler::instance().getFirstInReadyQ()->second.getPcb()->getState() == State::Exit)
			break;

//		unique_lock<mutex> guard(mx);
//		this_thread::sleep_for(chrono::seconds(4));
		while (this_thread::get_id() != scheduler::instance().getFirstInReadyQ()->first.get_id()) {
//			cv.wait(guard, [] { return threadActive; });	//make threadActive for each thread?
			this_thread::sleep_for(chrono::milliseconds(5));
		}

		ifstream inFile;
		inFile.open(process.getFilePath());

		if (!inFile) {

			cout << "Unable to open file.";
			exit(1);

		} else {
			readFile(&inFile, process);
		}

		inFile.close();

	}

}

ifstream * processManager::goToLine(ifstream *inFile, int lineNumber, process &process) {

	inFile->seekg(ios::beg);

	for (int i = 0; i < lineNumber - 1; i++) {
		inFile->ignore(1000,'\n');
	}

	return inFile;

}

void processManager::readFile(ifstream *inFile, process &process) {

	int linePC = process.getPcb()->getPc();

	goToLine(inFile, linePC, process);

	string line;
	while (getline(*inFile, line) && this_thread::get_id() == scheduler::instance().getFirstInReadyQ()->first.get_id()) {

		if (interruptSignal && signalActive) { break; }

		process.getPcb()->setPc(++linePC);

		execute(line, process);

		if (line.find("<CRITICAL_SECTION>") != -1) {

			if (lock.acquire()) {
				signalActive = false;
			} else {
				process.getPcb()->decrementPc();
				op.yield();
			}

		} else if (line.find("</CRITICAL_SECTION>") != -1) {
			lock.release();
			signalActive = true;
		}

	}

}

void processManager::execute(string line, process &process) {

	if (line.find("CALCULATE") != -1) {

		dp.updateState(Run, process.getPcb());

		int cyclesLeft;

		if (process.getPcb()->getCyclesLeft() == 0) {
			cyclesLeft = op.calculate(generateRandomNumber(false));
		} else {
			cyclesLeft = op.calculate(process.getPcb()->getCyclesLeft());
		}

		if (cyclesLeft > 0) {
			process.getPcb()->setCyclesLeft(cyclesLeft);
			process.getPcb()->decrementPc();
			op.yield();
		}

	} else if (line.find("I/O") != -1) {
		op.wait(generateRandomNumber(true));	//thread somewhere on wait?
	} else if (line.find("YIELD") != -1) {
		op.yield();
	} else if (line.find("OUT") != -1) {
		op.out(process);
	} else if (line.find("EXE") != -1) {
		op.exit();
	}

}

int processManager::generateRandomNumber(bool wait) {

	random_device rd;
	mt19937 gen(rd());

	int x, y;
	if (wait) {
		x = 25;
		y = 50;
	} else {
		x = 50;
		y = 100;
	}

	uniform_int_distribution<> range(x, y);
	int num = range(gen);

	return num;

}
