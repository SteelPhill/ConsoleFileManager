#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class WorkingWithDirectoriesCommand : public IMenuCommand
{
	IMenu* workingWithDirectoriesMenu;

public:
	WorkingWithDirectoriesCommand(IMenu* workingWithDirectoriesMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};