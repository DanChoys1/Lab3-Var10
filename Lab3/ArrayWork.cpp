#include <iostream>
#include <iomanip>

#include "Input.h"
#include "SaveData.h"
#include "Sort.h"

using namespace std;

unique_ptr<Input> choiceInputType();

void arrayWork(void) {
	unique_ptr<Input> inp = choiceInputType();

	Array arr = inp->Read();
	
	cout << "Input array:" << endl;
	arr.print();

	BubbleSort bubbleSort;
	Array arrayBubbleSort = bubbleSort.sort(arr);

	cout << "BubbleSort array:" << endl;
	arrayBubbleSort.print();

	SelectionSort selectionSort;
	Array arrSelectionSort = selectionSort.sort(arr);

	cout << "SelectionSort array:" << endl;
	arrSelectionSort.print();

	InsertionSort insertionSort;
	Array arrInsertionSort = insertionSort.sort(arr);

	cout << "InsertionSort array:" << endl;
	arrInsertionSort.print();

	ShellSort shellSort;
	Array arrShellSort = shellSort.sort(arr);

	cout << "ShellSort array:" << endl;
	arrShellSort.print();

	QuickSort quickSort;
	Array arrQuickSort = quickSort.sort(arr);

	cout << "QuickSort array:" << endl;
	arrQuickSort.print();

	cout << endl << "                Comparison   Permutation" << endl;
			cout << "Bubble Sort:" << setw(14) << bubbleSort.getComparison() << setw(14) << bubbleSort.getPermutation() << endl;
			cout << "Selection Sort:" << setw(11) << selectionSort.getComparison() << setw(14) << selectionSort.getPermutation() << endl;
			cout << "Insertion Sort:" << setw(11) << insertionSort.getComparison() << setw(14) << insertionSort.getPermutation() << endl;
			cout << "Shell Sort:" << setw(15) << shellSort.getComparison() << setw(14) << shellSort.getPermutation() << endl;
			cout << "Quick Sort:" << setw(15) << quickSort.getComparison() << setw(14) << quickSort.getPermutation() << endl;

	if (inp->isFileInput() == false) {
		saveInputArray(arr);
	}

	saveChangeArray(arrShellSort);
}
