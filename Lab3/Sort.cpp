#include <cmath>
#include <iostream>

#include "Sort.h"
#include "ArrayClass.h"

using namespace std;

int ISort::getComparison(void) {
	return comparison;
}

int ISort::getPermutation(void) {
	return permutation;
}

Array BubbleSort::sort(Array arr) {
	for (int j = 0; j < arr.getColumns(); j++) {

		for (int k = arr.getRows() - 1; k > 0; k--) {
			int cyclePermutations = 0;

			for (int i = 0; i < k; i++) {

				if (arr[i][j] > arr[i + 1][j]) {
					swap(arr[i][j], arr[i + 1][j]);
					permutation++;
					cyclePermutations++;
				}

				comparison++;
			}

			if (cyclePermutations == 0) {
				break;
			}

		}

	}

	return arr;
}

Array SelectionSort::sort(Array arr) {
	int minValueIndex = 0;

	for (int j = 0; j < arr.getColumns(); j++) {

		for (int k = 0; k < (arr.getRows() - 1); k++) {
			minValueIndex = k;

			for (int i = k + 1; i < arr.getRows(); i++) {

				if (arr[i][j] < arr[minValueIndex][j]) {
					minValueIndex = i;
				}

				comparison++;
			}

			if (minValueIndex != k) {
				swap(arr[minValueIndex][j], arr[k][j]);
				permutation++;
			}

		}

	}

	return arr;
}

Array InsertionSort::sort(Array arr) {

	for (int j = 0; j < arr.getColumns(); j++) {
		for (int i = 1; i < arr.getRows(); i++) {
			int rowValue = i;

			while ( ((rowValue - 1) >= 0) && (arr[rowValue][j] < arr[rowValue - 1][j]) ) {
				swap(arr[rowValue][j], arr[rowValue - 1][j]);

				permutation++;
				comparison++;
				rowValue--;
			}
			
			if ((rowValue - 1) != -1) {
				comparison++;
			}

		}

	}

	return arr;
}

Array ShellSort::sort(Array arr) {

	for (int j = 0; j < arr.getColumns(); j++) {
		int d = arr.getRows() / 2;

		while (d != 0) {

			for (int k = d; k < arr.getRows(); k++) {

				for (int i = k; (i - d) >= 0; i -= d) {

					if (arr[i][j] < arr[i - d][j]) {
						swap(arr[i][j], arr[i - d][j]);
						permutation++;
					} else {
						comparison++;
						break;
					}

					comparison++;
				}

			}

			d /= 2; 

		}

	}

	return arr;
}

Array QuickSort::recursionSort(Array arr, int low, int high, int j) {
	int center = (high + low) / 2;
	double safeValue = 0;

	for (int i = low; i < center; i++) {

		if (arr[i][j] > arr[center][j]) {
			safeValue = arr[i][j];

			for (int k = i; k < center; k++) {
				arr[k][j] = arr[k + 1][j];

			}

			arr[center][j] = safeValue;

			i--;
			center--;
			permutation++;
		}

		comparison++;

	}

	for (int i = high; i > center; i--) {

		if (arr[i][j] < arr[center][j]) {
			safeValue = arr[i][j];

			for (int k = i; k > center; k--) {
				arr[k][j] = arr[k - 1][j];
			}

			arr[center][j] = safeValue;

			i++;
			center++;
			permutation++;
		}

		comparison++;
	}

	if ((center - low) > 1) {
		arr = recursionSort(arr, low, center, j);
	}

	if ((high - center) > 1) {
		arr = recursionSort(arr, center + 1, high, j);
	}

	return arr;
}

Array QuickSort::sort(Array arr) {

	for (int j = 0; j < arr.getColumns(); j++) {
		arr = recursionSort(arr, 0, arr.getRows() - 1, j);
	}

	return arr;
}