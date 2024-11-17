#pragma once

#include <iostream>
#include "IDirectoryContentWriter.h"
#include "IMenuCommand.h"
#include "CurrentDirectory.h"
#include "DirectoryContentConsoleWriter.h"

class ShowContentsCurrentDirectoryCommand : public IMenuCommand
{
	IDirectoryContentWriter* contentWriter;

public:
	ShowContentsCurrentDirectoryCommand();
	~ShowContentsCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};