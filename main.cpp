/*
 * main.cpp
 *
 * Author: Serena Cheng
 */

#include "processManager.h"
#include "scheduler.h"
#include "memoryManager.h"
#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;


const char g_szClassName[] = "window";
const int ROUND_ROBIN_CYCLES = 50;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void driver();

HWND textField1, textField2, textField3, textField4, pcbField;
HWND readyList, waitList;

processManager pm;
memoryManager mm;
operation op;

char number[4];
thread mt;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx (
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "OPERATING SYSTEM SIMULATOR",
        WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 700,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    mt.join();
    return Msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {

    	case WM_CREATE: {

    		CreateWindow("STATIC", "How many text processors?", WS_VISIBLE | WS_CHILD, 10, 10, 190, 20, hwnd, NULL, NULL, NULL);
    		textField1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 10, 50, 20, hwnd, NULL, NULL, NULL);
    		CreateWindow("STATIC", "How many web browsers?", WS_VISIBLE | WS_CHILD, 10, 30, 190, 20, hwnd, NULL, NULL, NULL);
    		textField2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 30, 50, 20, hwnd, NULL, NULL, NULL);
    		CreateWindow("STATIC", "How many photo editors?", WS_VISIBLE | WS_CHILD, 10, 50, 190, 20, hwnd, NULL, NULL, NULL);
    		textField3 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 50, 50, 20, hwnd, NULL, NULL, NULL);
    		CreateWindow("STATIC", "How many music players?", WS_VISIBLE | WS_CHILD, 10, 70, 190, 20, hwnd, NULL, NULL, NULL);
    		textField4 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 70, 50, 20, hwnd, NULL, NULL, NULL);

    		CreateWindow("BUTTON", "Run", WS_VISIBLE| WS_CHILD, 300, 40, 40, 20, hwnd, (HMENU) 1, NULL, NULL);

    		CreateWindow("STATIC", "Waiting Queue", WS_VISIBLE | WS_CHILD, 100, 130, 100, 20, hwnd, NULL, NULL, NULL);
    		CreateWindow("STATIC", "Ready Queue", WS_VISIBLE | WS_CHILD, 330, 130, 100, 20, hwnd, NULL, NULL, NULL);
    		CreateWindow("STATIC", "Current PCB", WS_VISIBLE | WS_CHILD, 550, 130, 100, 20, hwnd, NULL, NULL, NULL);

    		waitList = CreateWindow("LISTBOX", "", WS_VSCROLL | WS_BORDER | WS_CHILD | WS_VISIBLE, 50, 150, 200, 400, hwnd, NULL, NULL, NULL);
    		readyList = CreateWindow("LISTBOX", "", WS_VSCROLL | WS_BORDER | WS_CHILD | WS_VISIBLE, 270, 150, 200, 400, hwnd, NULL, NULL, NULL);

    		pcbField = CreateWindow("STATIC", "", WS_VISIBLE | WS_BORDER | WS_CHILD, 500, 150, 200, 400, hwnd, NULL, NULL, NULL);
    	}
    		break;

    	case WM_COMMAND:

    		switch (LOWORD(wParam)) {
    			case 1: {
    				mt = thread(driver);
    				break;
    			}
    		}

    		break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);

    }
    return 0;
}

void driver() {

	int sum = 0;

	int response = GetWindowText(textField1, &number[0], 4);
	if (response == 1) {
		pm.createProcess(1, atoi(number));
		sum +=  atoi(number);
	}

	response = 0;
	response = GetWindowText(textField2, &number[0], 4);
	if (response == 1) {
		pm.createProcess(2, atoi(number));
		sum +=  atoi(number);
	}

	response = 0;
	response = GetWindowText(textField3, &number[0], 4);
	if (response == 1) {
		pm.createProcess(3, atoi(number));
		sum +=  atoi(number);
	}

	response = 0;
	response = GetWindowText(textField4, &number[0], 4);
	if (response == 1) {
		pm.createProcess(4, atoi(number));
		sum +=  atoi(number);
	}

	thread th[sum];
	vector<thread> threads;

	vector<process> processes = pm.getProcesses();

	int i = 0;
	for (process &p : processes) {

		pm.setMemory(p);

		th[i] = thread(&processManager::openProcess, &pm, ref(p));

		pair<thread, process> pair = make_pair(move(th[i]), p);

		if (mm.allocateMemory(p.getPcb()->getMemory())) {
			scheduler::instance().addToReadyQ(pair, false);
		} else {
			scheduler::instance().addToWaitQ(pair, false);
		}

		threads.push_back(move(th[i]));
		i++;

	}

	int currentCycle;

	while (scheduler::instance().getReadyQSize() > 0 || scheduler::instance().getWaitQSize() > 0) {

		interruptSignal = false;

		currentCycle = 0;
		while (currentCycle < ROUND_ROBIN_CYCLES && !interruptSignal) {

			currentCycle++;

			if (rand() > (RAND_MAX * 0.9)) {
				interruptSignal = true;
			}

		}

		if (!interruptSignal) { interruptSignal = true; }

	}

	for (thread &th : threads) {
		if (th.joinable()){
			th.join();
		}
	}

	threads.clear();
	processes.clear();

}

void updateLists(int mode, bool inReadyOrWaitQ, string data) {

	int pos;

	switch (mode) {

		case 1: { //Adding in RQ

			if (inReadyOrWaitQ) {
				char c[50];
				SendMessage(waitList, LB_GETTEXT, 0, (WPARAM) 0 | (LPARAM) c);
				pos = (int) SendMessage(readyList, LB_ADDSTRING, 0, (LPARAM) c);
				SendMessage(readyList, LB_SETITEMDATA, pos, (LPARAM) 0);

				SendMessage(waitList, LB_DELETESTRING, 0, (WPARAM) 0);
			} else {
				char charArr[data.length() + 1];
				strcpy(charArr, data.c_str());
				pos = (int) SendMessage(readyList, LB_ADDSTRING, 0, (LPARAM) charArr);
				SendMessage(readyList, LB_SETITEMDATA, pos, (LPARAM) 0);
			}

		}

		break;

		case 2: { //Yielding in RQ

			char c[50];
			SendMessage(readyList, LB_GETTEXT, 0, (WPARAM) 0 | (LPARAM) c);
			pos = (int) SendMessage(readyList, LB_ADDSTRING, 0, (LPARAM) c);
			SendMessage(readyList, LB_SETITEMDATA, pos, (LPARAM) 0);

			SendMessage(readyList, LB_DELETESTRING, 0, (WPARAM) 0);

		}

		break;

		case 3: { //Adding in WQ

			if (inReadyOrWaitQ) {
				char c[50];
				SendMessage(readyList, LB_GETTEXT, 0, (WPARAM) 0 | (LPARAM) c);
				pos = (int) SendMessage(waitList, LB_ADDSTRING, 0, (LPARAM) c);
				SendMessage(waitList, LB_SETITEMDATA, pos, (LPARAM) 0);

				SendMessage(readyList, LB_DELETESTRING, 0, (WPARAM) 0);
			} else {
				char charArr[data.length() + 1];
				strcpy(charArr, data.c_str());
				pos = (int) SendMessage(waitList, LB_ADDSTRING, 0, (LPARAM) charArr);
				SendMessage(waitList, LB_SETITEMDATA, pos, (LPARAM) 0);
			}

		}

		break;

		case 4: { //Yield in WQ

			char c[50];
			SendMessage(waitList, LB_GETTEXT, 0, (WPARAM) 0 | (LPARAM) c);
			pos = (int) SendMessage(waitList, LB_ADDSTRING, 0, (LPARAM) c);
			SendMessage(waitList, LB_SETITEMDATA, pos, (LPARAM) 0);

			SendMessage(waitList, LB_DELETESTRING, 0, (WPARAM) 0);

		}
		break;

		case 5: //Remove from RQ
			SendMessage(readyList, LB_DELETESTRING, 0, (WPARAM) 0);
			break;

	}

}

void updatePCB(process &process) {

	string s = op.out(process);
	char charArr[s.length() + 1];
	strcpy(charArr, s.c_str());

	SetWindowText(pcbField, charArr);

}

