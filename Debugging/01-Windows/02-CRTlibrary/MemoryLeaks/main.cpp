#include <iostream>
#include <cstring>
#include <windows.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main() {
	_CrtMemState sOld;
	_CrtMemState sNew;
	_CrtMemState sDiff;
	_CrtMemCheckpoint(&sOld); //take a snapshot

	char* s = new char[17];
	strcpy_s(s, 17, "stackoverflow_pb");

	char* ss = new char[14];
	strcpy_s(ss, 14, "stackoverflow");

	delete[]ss;

	_CrtMemCheckpoint(&sNew); //take a snapshot 

	if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
	{
		OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
		_CrtMemDumpStatistics(&sDiff);
		OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
		_CrtMemDumpAllObjectsSince(&sOld);
		OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
		_CrtDumpMemoryLeaks();
	}

	return 0;
}
