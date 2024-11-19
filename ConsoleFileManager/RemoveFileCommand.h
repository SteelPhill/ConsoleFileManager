#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class RemoveFileCommand : public IMenuCommand
{
	IMenu* removeFileMenu;

public:
	RemoveFileCommand(IMenu* removeFileMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};