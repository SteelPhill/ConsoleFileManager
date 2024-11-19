#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class WorkingWithFilesCommand : public IMenuCommand
{
	IMenu* workingWithFilesMenu;

public:
	WorkingWithFilesCommand(IMenu* workingWithFilesMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};