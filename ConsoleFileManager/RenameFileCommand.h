#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class RenameFileCommand : public IMenuCommand
{
	IMenu* renameFileMenu;

public:
	RenameFileCommand(IMenu* renameFileMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};