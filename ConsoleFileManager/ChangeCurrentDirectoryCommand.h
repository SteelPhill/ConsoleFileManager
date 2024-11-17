#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ChangeCurrentDirectoryToEnteredCommand.h"
#include "ChangeCurrentDirectoryToPreviousCommand.h"
#include "ChangeCurrentDirectoryToSelectedCommand.h"
#include "ConsoleMenu.h"

class ChangeCurrentDirectoryCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};