#pragma once

#include <iostream>
#include <string>
#include "IStringReader.h"

class ConsoleStringReader : public IStringReader
{
public:
	std::wstring Read() const override;
};