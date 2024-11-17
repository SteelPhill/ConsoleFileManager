#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "CopyDirectoryCommand.h"
#include "CreateDirectoryCommand.h"
#include "RelocateDirectoryCommand.h"
#include "RemoveDirectoryCommand.h"
#include "RenameDirectoryCommand.h"
#include "ShowDirectorySizeCommand.h"

class WorkingWithDirectoriesCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};