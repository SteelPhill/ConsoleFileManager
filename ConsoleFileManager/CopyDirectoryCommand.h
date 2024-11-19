#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class CopyDirectoryCommand : public IMenuCommand
{
	IMenu* copyDirectoryMenu;

public:
	CopyDirectoryCommand(IMenu* copyDirectoryMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};