#pragma once

#include <iostream>
#include "IStringSpacesChecker.h"

class StringSpacesChecker : public IStringSpacesChecker
{
public:
    bool Check(const std::wstring& text) const override;
};