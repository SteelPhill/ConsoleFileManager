#pragma once

#include <iostream>
#include <vector>
#include "IColoredTextWriter.h"
#include "IMenuCommand.h"
#include "IMenuWriter.h"
#include "IStringSpacesChecker.h"
#include "ColoredTextConsoleWriter.h"
#include "Constants.h"
#include "CurrentDirectory.h"
#include "StringSpacesChecker.h"

class ConsoleMenuWriter : public IMenuWriter
{
    IColoredTextWriter* coloredTextWriter;
    IStringSpacesChecker* spacesChecker;

public:
    ConsoleMenuWriter();
    ~ConsoleMenuWriter();

    void Write(const std::wstring& title, const std::vector<IMenuCommand*> commands, int& selector) const override;
    void Write(const std::wstring& title, const std::vector<std::wstring> items, int& selector) const override;
};