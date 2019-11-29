/*
 * program.cpp
 *
 * Author: Serena Cheng
 */

#include "process.h"

using namespace std;


process::process(string name, string path) {

	currentPcb.setMemory(0);

	setName(name);
	setFilePath(path);

}
process::~process() {}

pcb * process::getPcb() { return &currentPcb; }

string process::getName() { return name; }
void process::setName(string fileName) {
	name = fileName;
}

string process::getFilePath() { return filePath; }
void process::setFilePath(string path) {
	filePath = path;
}

void process::setProcessId(int id) {
	currentPcb.setProcessId(id);
}
