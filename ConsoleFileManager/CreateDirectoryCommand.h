#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "CreateDirectoryInCurrentDirectoryCommand.h"
#include "CreateDirectoryInEnteredDirectoryCommand.h"

class CreateDirectoryCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};