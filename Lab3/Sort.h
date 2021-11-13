#pragma once

#include "ArrayClass.h"

class ISort {
protected:
	int comparison = 0;
	int permutation = 0;

public:

	virtual Array sort(Array arr) = 0;

	int getComparison(void);

	int getPermutation(void);

	virtual ~ISort() = default;

};

class BubbleSort final : public ISort {
public:

	Array sort(Array arr);

};

class SelectionSort final : public ISort {
public:

	Array sort(Array arr) ;

};

class InsertionSort final : public ISort {
public:

	Array sort(Array arr);

};

class ShellSort final : public ISort {
public:

	Array sort(Array arr);

};

class QuickSort final : public ISort {

	Array recursionSort(Array arr, int low, int high, int j);

public:

	Array sort(Array arr);

};