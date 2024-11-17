#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "IMenuWriter.h"
#include "ConsoleMenuWriter.h"
#include "Constants.h"

class ConsoleMenuSelector : public IMenuSelector
{
    IMenuWriter* menuWriter;

public:
    ConsoleMenuSelector();
    ~ConsoleMenuSelector();

    int Select(const std::wstring& title, const std::vector<IMenuCommand*> commands, int& selector) const override;
    std::wstring Select(const std::wstring& title, const std::vector<std::wstring> items) const override;
};