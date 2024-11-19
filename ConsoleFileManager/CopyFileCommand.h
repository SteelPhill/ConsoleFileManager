#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class CopyFileCommand : public IMenuCommand
{
	IMenu* copyFileMenu;

public:
	CopyFileCommand(IMenu* copyFileMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};