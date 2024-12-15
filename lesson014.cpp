#include <iostream>
#include <exception>
#include <climits>
#include <thread>

/*
using namespace std;

int* ptr[5]{};
void NewHandler() {
	using namespace std::chrono_literals;
	cout << "Failed to allocate memory" << endl;
	std::this_thread::sleep_for(1s);
	delete[] ptr[0];
	ptr[0] = nullptr;
}
int main() {
	std::set_new_handler(NewHandler);
	try {
		for (int i = 0; i < 5; ++i) {
			cout << "Allocating memory #" << i << endl;
			ptr[i] = new int[INT_MAX / 10];
			cout << "Success #" << i << endl;
		}
	}
	catch (std::exception& ex) {
		cout << "Exception: " << ex.what() << endl;
	}
	return 0;
}

*/
