#include <stdio.h>
#include <limits.h>
#include <windows.h>
#include <exception>
#include <iostream>

using namespace std;


int main() {
	HINSTANCE hDll = LoadLibraryA(R"(..\..\VSCppDll\Debug\VSCppdll.dll)");
	if (hDll == NULL) {
		puts("Could not load dll");
		return -1;
	}
	int** (*pfn)(int, int);
	pfn = (int** (*)(int, int))GetProcAddress(hDll, (LPCSTR)1);
	if (pfn == NULL) {
		puts("Could not locate function");
		goto EXIT;
	}
	try {
		int rows = 1000;
		int columns = 100;
		int** pData = pfn(rows, columns);
		if (pData == NULL) {
			printf("Data could not be retrieved\n");
			goto EXIT;
		}
		puts("Processing data");
	}
	catch (std::exception& ex) {
		cout << "[main] Caught exception:" << ex.what() << endl;
	}

EXIT:
	FreeLibrary(hDll);

	return 0;
}


