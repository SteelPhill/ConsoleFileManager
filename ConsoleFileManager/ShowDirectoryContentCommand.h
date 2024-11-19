#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class ShowDirectoryContentCommand : public IMenuCommand
{
	IMenu* showDirectoryContentMenu;

public:
	ShowDirectoryContentCommand(IMenu* showDirectoryContentMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};