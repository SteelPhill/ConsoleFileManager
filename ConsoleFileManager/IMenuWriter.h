#pragma once

#include <iostream>
#include <vector>
#include "IMenuCommand.h"

class IMenuWriter
{
public:
    virtual ~IMenuWriter() = default;

    virtual void Write(const std::wstring& title, const std::vector<IMenuCommand*> commands, int& selector) const = 0;
    virtual void Write(const std::wstring& title, const std::vector<std::wstring> commands, int& selector) const = 0;
};