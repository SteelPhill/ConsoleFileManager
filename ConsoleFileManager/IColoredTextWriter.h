#pragma once

#include <iostream>

class IColoredTextWriter
{
public:
    virtual ~IColoredTextWriter() = default;

    virtual void Write(const std::wstring text, const int numericColorCode) = 0;
    virtual void Write(const long long value, const int numericColorCode) = 0;
};