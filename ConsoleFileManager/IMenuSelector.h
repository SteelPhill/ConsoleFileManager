#pragma once

#include <iostream>
#include <vector>
#include "IMenuCommand.h"

class IMenuSelector
{
public:
    virtual ~IMenuSelector() = default;

    virtual int Select(const std::wstring& title, const std::vector<IMenuCommand*> commands, int& selector) const = 0;
    virtual std::wstring Select(const std::wstring& title, const std::vector<std::wstring> items) const = 0;
};