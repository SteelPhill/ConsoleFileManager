#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class ChangeCurrentDirectoryCommand : public IMenuCommand
{
	IMenu* changeCurrentDirectoryMenu;

public:
	ChangeCurrentDirectoryCommand(IMenu* changeCurrentDirectoryMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};