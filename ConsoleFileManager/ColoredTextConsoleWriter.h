#pragma once

#include <iostream>
#include <Windows.h> 
#include "IColoredTextWriter.h"
#include "Constants.h"

class ColoredTextConsoleWriter : public IColoredTextWriter
{
    HANDLE hConsoleOutput;

public:
    ColoredTextConsoleWriter();

    virtual void Write(const std::wstring text, const int numericColorCode) override;
    virtual void Write(const long long value, const int numericColorCode) override;
};