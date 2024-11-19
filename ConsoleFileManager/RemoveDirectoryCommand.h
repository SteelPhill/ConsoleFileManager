#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class RemoveDirectoryCommand : public IMenuCommand
{
	IMenu* removeDirectoryMenu;

public:
	RemoveDirectoryCommand(IMenu* removeDirectoryMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};