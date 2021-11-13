#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "OpenFile.h"
#include "ArrayClass.h"

using namespace std;

void saveInputArray(Array arr) {
	cout << endl << "Do you want to save the initial data in a file?" << endl
		<< "y - Yes" << endl
		<< "n - No" << endl
		<< "Choice: ";

	string choiceRepeat = "";

	do {
		cin >> choiceRepeat;

		if (choiceRepeat.compare("n") && choiceRepeat.compare("y")) {
			cout << "There is no such action." << endl
				<< "Choice: ";
		}

	} while (choiceRepeat.compare("n") && choiceRepeat.compare("y"));

	if (choiceRepeat.compare("n")) {
		ofstream file = openFileOutput();

		file << arr.getRows() << endl << arr.getColumns() << endl;

		int length = arr.getMaxLengthValue();

		for (int i = 0; i < arr.getRows(); i++) {

			for (int j = 0; j < arr.getColumns(); j++) {

				file << setw(length) << arr[i][j] << " ";
			
			}

			file << endl;

		}

		file.close();
	}

};

void saveChangeArray(Array arr) {
	cout << endl << "Do you want to save the result of the program?" << endl
		<< "y - Yes" << endl
		<< "n - No" << endl
		<< "Choice: ";

	string choiceRepeat = "";

	do {
		cin >> choiceRepeat;

		if (choiceRepeat.compare("n") && choiceRepeat.compare("y")) {
			cout << "There is no such action." << endl
				<< "Choice: ";
		}

	} while (choiceRepeat.compare("n") && choiceRepeat.compare("y"));

	if (choiceRepeat.compare("n")) {
		ofstream file;
		file = openFileOutput();

		for (int i = 0; i < arr.getRows(); i++) {

			for (int j = 0; j < arr.getColumns(); j++) {

				file << arr[i][j] << " ";

			}

			file << endl;

		}

		file.close();
	}

}