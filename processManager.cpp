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

			if (line.find("Memory") != string::npos) {
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

		while (this_thread::get_id() != scheduler::instance().getFirstInReadyQ()->first.get_id()) {
			this_thread::sleep_for(chrono::milliseconds(5));
		}

		ifstream inFile;
		inFile.open(process.getFilePath());

		if (!inFile) {

			cout << "Unable to open file: " + process.getPcb()->getProcessId() << endl;
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

		updatePCB(process);

		if (interruptSignal && signalActive) {
			op.yield();
			break;
		}

		process.getPcb()->setPc(++linePC);

		execute(line, process);

		if (line.find("<CRITICAL_SECTION>") != string::npos) {

			if (lock.acquire()) {
				signalActive = false;
			} else {
				process.getPcb()->decrementPc();
				op.yield();
			}

		} else if (line.find("</CRITICAL_SECTION>") != string::npos) {
			lock.release();
			signalActive = true;
		}

	}

}

void processManager::execute(string line, process &process) {

	if (line.find("CALCULATE") != string::npos) {

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

	} else if (line.find("I/O") != string::npos) {
		op.wait(generateRandomNumber(true));	//thread somewhere on wait?
	} else if (line.find("YIELD") != string::npos) {
		op.yield();
	} else if (line.find("OUT") != string::npos) {
		cout << op.out(process) << endl;
	} else if (line.find("EXE") != string::npos) {
		op.exit();
	}

}

int processManager::generateRandomNumber(bool wait) {

	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> range(25, 50);
	int num = range(gen);

	return num;

}
