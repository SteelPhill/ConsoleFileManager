#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "CreateFileInCurrentDirectoryCommand.h"
#include "CreateFileInEnteredDirectoryCommand.h"

class CreateFileCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};