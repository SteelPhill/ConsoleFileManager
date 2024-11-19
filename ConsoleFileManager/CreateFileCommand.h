#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class CreateFileCommand : public IMenuCommand
{
	IMenu* createFileMenu;

public:
	CreateFileCommand(IMenu* createFileMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};