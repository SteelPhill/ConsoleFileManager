#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class ShowFileSizeCommand : public IMenuCommand
{
	IMenu* showFileSizeMenu;

public:
	ShowFileSizeCommand(IMenu* showFileSizeMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};