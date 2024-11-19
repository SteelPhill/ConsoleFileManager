#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class ShowDirectorySizeCommand : public IMenuCommand
{
	IMenu* showDirectorySizeMenu;

public:
	ShowDirectorySizeCommand(IMenu* showDirectorySizeMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};