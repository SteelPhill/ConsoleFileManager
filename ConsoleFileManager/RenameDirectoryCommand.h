#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "RenameDirectoryFromCurrentDirectoryCommand.h"
#include "RenameEnteredDirectoryCommand.h"

class RenameDirectoryCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};