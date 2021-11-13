#include <iostream>

#include "ArrayClass.h"
#include "Sort.h"
#include "Input.h"

using namespace std;

const int ALL_TEST_PASSED = 5;

void test(void) {

	const int rows = 20;
	const int columns = 20;
	const int randomLimits = 100;

	Array arr(rows, columns);

	srand((unsigned int)time(NULL));


	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			if (rand() % 2) {

				arr[i][j] = rand() % randomLimits;

			}
			else {

				arr[i][j] = -1 * (rand() % randomLimits);

			}

		}

	}

	int valueTestPassed = 0;

	BubbleSort bubbleSort;
	Array arrayBubbleSort = bubbleSort.sort(arr);

	SelectionSort selectionSort;
	Array arrSelectionSort = selectionSort.sort(arr);

	InsertionSort insertionSort;
	Array arrInsertionSort = insertionSort.sort(arr);

	ShellSort shellSort;
	Array arrShellSort = shellSort.sort(arr);

	QuickSort quickSort;
	Array arrQuickSort = quickSort.sort(arr);

	arr.sort();

	if (arr == arrayBubbleSort) {
		valueTestPassed++;
	} else {
		cout << endl << "Test1 faild" << endl;
	}

	if (arr == arrSelectionSort) {
		valueTestPassed++;
	} else {
		cout << endl << "Test2 faild" << endl;
	}

	if (arr == arrInsertionSort) {
		valueTestPassed++;
	} else {
		cout << endl << "Test3 faild" << endl;
	}

	if (arr == arrShellSort) {
		valueTestPassed++;
	} else {
		cout << endl << "Test4 faild" << endl;
	}

	if (arr == arrQuickSort) {
		valueTestPassed++;
	} else {
		cout << endl << "Test5 faild" << endl;
	}

	if (valueTestPassed == ALL_TEST_PASSED) {
		cout << endl << "All test passed" << endl;
	}

}