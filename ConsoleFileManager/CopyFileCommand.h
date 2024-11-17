#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "CopyEnteredFileCommand.h"
#include "CopyFileFromCurrentDirectoryCommand.h"

class CopyFileCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};