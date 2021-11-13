#pragma once

class Array final {
	double **arr = nullptr;
	int columns = 0;
	int rows = 0;

public:
	Array(int arrayRows, int arrayColumns);

	Array(const Array& oldArr);

	~Array();

	int getColumns(void);

	int getRows(void);

	int getMaxLengthValue(void);

	void print(void);

	void sort(void);

	double* operator [] (int index);

	bool operator == (Array& oldArr);

	Array & operator = (Array&& oldArray);

	Array & operator = (Array& oldArray) = delete;

};
