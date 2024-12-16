#include "utils.h"

#include <iostream>
using namespace std;

int** Create(int row, int column) {
	cout << "[Dll] Creating matrix of " << row << "x" << column << endl;

	int** ptr = NULL;
	int i = 0;
	try {
		ptr = new int* [row];
		for(; i < row; ++i) {
			ptr[i] = new int[column];
		}
	}catch(std::exception& ex) {
		cout << "[Dll] Exception caught at row # " << i << " with reason -> " << ex.what() << endl;
		throw;
	}
	return ptr;
}

void Destroy(int** ptr, int row, int column) {
	for (int i = 0; i < row, ++i) {
		delete[] ptr[i];
	}
	delete[] ptr;
}
