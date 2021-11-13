#include <iomanip>
#include <iostream>
#include <string>

#include "ArrayClass.h"

using namespace std;

Array::Array(int arrayRows, int ArrayColumns) : rows(arrayRows), columns(ArrayColumns) {
	arr = new double*[rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new double[columns];
	}

}

Array::Array(const Array& oldArray) : columns(oldArray.columns), rows(oldArray.rows) {
	arr = new double*[rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new double[columns];
	}

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {
			arr[i][j] = oldArray.arr[i][j];
		}

	}

}

Array::~Array() {

	for (int i = 0; i < rows; i++) {
		delete[](arr[i]);
	}

	delete[] arr;
}

int Array::getColumns(void) {
	return columns;
}

int Array::getRows(void) {
	return rows;
}

int Array::getMaxLengthValue(void) {
	double maxValue = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			if (abs(arr[i][j]) > abs(maxValue)) {
				maxValue = arr[i][j];
			}

		}
	}

	string stringMaxValue = to_string(maxValue);
	
	return stringMaxValue.length();
}

void Array::print(void) {
	int length = getMaxLengthValue();
	
	for (int i = 0; i < rows; i++) {
		cout << "|";

		for (int j = 0; j < columns; j++) {
			cout << setw(length) << arr[i][j] << "|";
		}

		cout << endl;
	}

}

void Array::sort(void) {
	for (int j = 0; j < columns; j++) {

		for (int k = rows - 1; k > 0; k--) {
			int cyclePermutations = 0;

			for (int i = 0; i < k; i++) {

				if (arr[i][j] > arr[i + 1][j]) {
					swap(arr[i][j], arr[i + 1][j]);
					cyclePermutations++;
				}
			}

			if (cyclePermutations == 0) {
				break;
			}

		}

	}
}

Array & Array::operator = (Array&& oldArray) {

	if (this != &oldArray) {

		if (arr != nullptr) {
			for (int i = 0; i < rows; i++) {
				delete[](arr[i]);
			}

			delete arr;
		}

		rows = oldArray.rows;
		columns = oldArray.columns;

		arr = oldArray.arr;
		oldArray.arr = nullptr;

		oldArray.rows = 0;
		oldArray.columns = 0;
	}

	return *this;
}

double* Array::operator [] (int index) {
	return arr[index];
}

bool Array::operator == (Array& compareArr) {

	if (compareArr.rows == rows && compareArr.columns == columns) {

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (arr[i][j] != compareArr[i][j]) {
					return false;
				}
			}
		}

		return true;
	}

	return false;
}