#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "RelocateEnteredFileCommand.h"
#include "RelocateFileFromCurrentDirectoryCommand.h"

class RelocateFileCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};