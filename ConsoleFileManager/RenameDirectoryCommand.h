#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class RenameDirectoryCommand : public IMenuCommand
{
	IMenu* renameDirectoryMenu;

public:
	RenameDirectoryCommand(IMenu* renameDirectoryMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};