#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "CopyDirectoryFromCurrentDirectoryCommand.h"
#include "CopyEnteredDirectoryCommand.h"

class CopyDirectoryCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};