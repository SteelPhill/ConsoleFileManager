#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class RelocateFileCommand : public IMenuCommand
{
	IMenu* relocateFileMenu;

public:
	RelocateFileCommand(IMenu* relocateFileMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};