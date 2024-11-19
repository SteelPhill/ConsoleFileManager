#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class CreateDirectoryCommand : public IMenuCommand
{
	IMenu* createDirectoryMenu;

public:
	CreateDirectoryCommand(IMenu* createDirectoryMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};