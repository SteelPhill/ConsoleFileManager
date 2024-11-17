#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "RenameEnteredFileCommand.h"
#include "RenameFileFromCurrentDirectoryCommand.h"

class RenameFileCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};