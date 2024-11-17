#pragma once

#include <iostream>

class IStringReader
{
public:
	virtual ~IStringReader() = default;

	virtual std::wstring Read() const = 0;
};