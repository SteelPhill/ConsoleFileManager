#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "CopyFileCommand.h"
#include "CreateFileCommand.h"
#include "RelocateFileCommand.h"
#include "RemoveFileCommand.h"
#include "RenameFileCommand.h"
#include "ShowFileSizeCommand.h"

class WorkingWithFilesCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};