#include <iostream>
#include <limits>

using namespace std;

int getInt(void) {
	int input = 0;
	cin >> input;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input Error. Enter the number." << endl;
		cin >> input;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

double getDouble(void) {
	double input = 0;
	cin >> input;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input Error. Enter the number." << endl;
		cin >> input;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}