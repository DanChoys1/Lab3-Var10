#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

ofstream openFileOutput(void) {
	ofstream file;
	string path = "";

	bool fileOpenComplit = false;
	
	do {
		cout << "Enter the path to the file" << endl;

		cin >> path;

		if (ifstream(path)) {
			error_code ec;

			if (!filesystem::is_regular_file(path, ec)) {
				cout << "The file could not be opened. Try again." << endl;
				continue;
			}

			cout << "This file exists. Do you want overwrite a file?" << endl;
			string choice;

			do {
				cout << "y - Yes" << endl
					<< "n - No" << endl
					<< "Choice: ";

				cin >> choice;

				if (choice.compare("n") && choice.compare("y")) {
					cout << "There is no such action." << endl
						<< "Do you want overwrite a file?" << endl;
				}

			} while (choice.compare("n") && choice.compare("y"));

			if (!choice.compare("n")) {
				continue;
			}

		}

		file.open(path);

		error_code ec;

		if (!filesystem::is_regular_file(path, ec)) {
			cout << "The file could not be opened." << endl;
			continue;
		}

		if (!file.is_open()) {
			cout << "The file could not be opened." << endl;
			continue;
		}

		fileOpenComplit = true;
	} while (!fileOpenComplit);

	return file;
}

ifstream openFileInput(void) {

	cout << "Enter the path to the file" << endl;

	ifstream file;
	string path;
	
	bool isOpeningFile = false;

	do {
		error_code ec;

		do {
			cin >> path;

			if (!filesystem::is_regular_file(path, ec)) {
				cout << "The file could not be opened." << endl
					<< "Enter a different name or path to the file: ";
			}

		} while (!filesystem::is_regular_file(path, ec));

		file.open(path);

		if (file.is_open()) {

			isOpeningFile = true;

		} else {
			cout << "The file could not be opened." << endl
				<< "Enter a different name or path to the file: ";

			isOpeningFile = false;
		}

	} while (isOpeningFile == false);

	return file;
}
