#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#include "OpenFile.h"
#include "ArrayClass.h"
#include "Input.h"

using namespace std;

enum ChoiceTypeInput {
	CHOICE_KEYBOARD = 1,
	CHOICE_FILE,
	CHOICE_RANDOM,
};

int getInt(void);
double getDouble(void);
void valueInputMenu(void);

Array KeyboardInput::Read() {
	int numberRows = 0;

	do {
		cout << endl << "Enter the number of rows of the array: ";
		numberRows = getInt();

		if (numberRows <= 0) {
			cout << endl << "rows must be > 0. Try again." << endl;
		}

	} while (numberRows <= 0);

	int numberColumns = 0;

	do {
		cout << endl << "Enter the number of columns of the array: ";
		numberColumns = getInt();

		if (numberColumns <= 0) {
			cout << endl << "columns must be > 0. Try again." << endl;
		}

	} while (numberColumns <= 0);

	Array arr(numberRows, numberColumns);

	for (int i = 0; i < numberRows; i++) {

		for (int j = 0; j < numberColumns; j++) {

			cout << i + 1 << '.' << j + 1 << ")";
			arr[i][j] = getDouble();

		}

	}

	return arr;
}

bool KeyboardInput::isFileInput() {
	return false;
}

Array FileInput::Read() {
	int rows = 0;
	int columns = 0;

	while (true) {
		cout << endl << "Input data" << endl;
		ifstream file = openFileInput();

		try {
			string valueInFile;

			getline(file, valueInFile);
			rows = stoi(valueInFile);

			if (rows <= 0) {
				cout << endl << "rows in file must be > 0. Try again." << endl;
				continue;
			}			

			getline(file, valueInFile);
			columns = stoi(valueInFile);

			if (columns <= 0) {
				cout << endl << "columns in file must be > 0. Try again." << endl;
				continue;
			}

			Array arr(rows, columns);

			for (int i = 0; i < rows; i++) {
				string value;
				string RowValues = "";
				getline(file, RowValues);

				int columnNumber = 0;

				for (int j = 0; j < RowValues.length(); j++) {

					if ((RowValues[j] == ' ') && (value != "")) {

						arr[i][columnNumber] = stod(value);

						columnNumber++;
						value = "";
					} else if (RowValues[j] != ' ') {

						value += RowValues[j];

					}

				}

			}

			cout << "Input rows = " << rows << endl;
			cout << "Input columns = " << columns << endl;

			file.close();

			return arr;
		} catch (invalid_argument) {
			cout << endl << "The value in the file are not correct. Try again." << endl;
		}

	}

}

bool FileInput::isFileInput() {
	return true;
}

Array RandomInput::Read() {
	int rows = 0;
	int columns = 0;

	do {
		cout << endl << "Enter the number of rows of the array: ";
		rows = getInt();

		if (rows <= 0) {
			cout << endl << "rows must be > 0. Try again." << endl;
		}

	} while (rows <= 0);

	do {
		cout << endl << "Enter the number of columns of the array: ";
		columns = getInt();

		if (columns <= 0) {
			cout << endl << "columns must be > 0. Try again." << endl;
		}

	} while (columns <= 0);

	Array arr(rows, columns);

	srand((unsigned int)time(NULL));

	int randomLimits = 0;

	do {
		cout << endl << "Random numbers in a range (-a, a)" << endl
			<< "Enter a: ";
		randomLimits = getInt();

		if (randomLimits <= 0) {
			cout << endl << "a must be > 0. Try again." << endl;
		}

	} while (randomLimits <= 0);

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			if (rand() % 2) {

				arr[i][j] = rand() % randomLimits;

			} else {

				arr[i][j] = -1 * (rand() % randomLimits);

			}

		}

	}

	return arr;
}

bool RandomInput::isFileInput() {
	return false;
}

unique_ptr<Input> choiceInputType() {
	int choice = 0;

	do {
		valueInputMenu();
		choice = getInt();

		if (choice == CHOICE_KEYBOARD) {

			return unique_ptr<KeyboardInput>(new KeyboardInput);

		} else if (choice == CHOICE_FILE) {

			return unique_ptr<FileInput>(new FileInput);

		} else if (choice == CHOICE_RANDOM) {

			return unique_ptr<RandomInput>(new RandomInput);

		} else {

			cout << "There is no such action" << endl;

		}

	} while ((choice != CHOICE_KEYBOARD) && (choice != CHOICE_FILE)
		&& (choice != CHOICE_RANDOM));

	return 0;
}
