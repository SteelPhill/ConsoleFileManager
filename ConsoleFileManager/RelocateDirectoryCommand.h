#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class RelocateDirectoryCommand : public IMenuCommand
{
	IMenu* relocateDirectoryMenu;

public:
	RelocateDirectoryCommand(IMenu* relocateDirectoryMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};