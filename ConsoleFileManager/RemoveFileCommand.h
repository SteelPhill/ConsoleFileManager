#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "RemoveEnteredFileCommand.h"
#include "RemoveFileFromCurrentDirectoryCommand.h"

class RemoveFileCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};