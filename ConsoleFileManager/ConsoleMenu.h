#pragma once

#include <iostream>
#include <vector>
#include "IColoredTextWriter.h"
#include "IMenu.h"
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "ColoredTextConsoleWriter.h"
#include "ConsoleMenuSelector.h"
#include "Constants.h"
#include "CurrentDirectory.h"

class ConsoleMenu : public IMenu
{
	std::wstring title;
	std::vector<IMenuCommand*> commands;
	IColoredTextWriter* coloredTextWriter;
	IMenuSelector* menuSelector;

	void ExecuteCommand(const int selector);

public:
	ConsoleMenu(const std::wstring& title = L"");
	~ConsoleMenu();

	void AddCommand(IMenuCommand* command) override;
	void Start() override;
};