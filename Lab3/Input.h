#pragma once

#include "ArrayClass.h"

class Input {
public:

	virtual Array Read() = 0;

	virtual bool isFileInput() = 0;

	virtual ~Input() = default;

};

class KeyboardInput final : public Input {
public:

	Array Read();

	bool isFileInput();
};

class FileInput final : public Input {
public:

	Array Read();

	bool isFileInput();
};

class RandomInput final : public Input {
public:

	Array Read();

	bool isFileInput();
};

