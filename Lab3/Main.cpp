#include <iostream>
#include <string>

#include "MainMenu.h"

using namespace std;

enum ChoiceTypeInput {
	CHOICE_ARRAY = 1,
	CHOICE_TESTING
};

int getInt();
void arrayWork();
void test();

int main() {
	greeting();

	int choice = 0;
	string isChoiceRepeat = "";

	do {

		do {
			mainMenu();
			choice = getInt();

			switch (choice) {
			case CHOICE_ARRAY:

				arrayWork();

				break;
			case CHOICE_TESTING:

				test();

				break;
			default:
				cout << "There is no such action. Try again" << endl;
			}

		} while ( (choice != CHOICE_ARRAY) && (choice != CHOICE_TESTING) );

		do {
			endProgramMenu();

			cin >> isChoiceRepeat;

			if (isChoiceRepeat.compare("n") && isChoiceRepeat.compare("y")) {
				cout << "There is no such action." << endl;
			}

		} while (isChoiceRepeat.compare("n") && isChoiceRepeat.compare("y"));

	} while (isChoiceRepeat.compare("n"));

	return 0;
}
