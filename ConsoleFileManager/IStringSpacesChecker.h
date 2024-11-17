#pragma once

#include <iostream>

class IStringSpacesChecker
{
public:
    virtual ~IStringSpacesChecker() = default;

    virtual bool Check(const std::wstring& text) const = 0;
};