#pragma once

#include <iostream>
#include "IDirectoryContentWriter.h"
#include "IMenuCommand.h"
#include "CurrentDirectory.h"
#include "DirectoryContentConsoleWriter.h"

class ShowContentsCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	IDirectoryContentWriter* contentWriter;

public:
	ShowContentsCurrentDirectoryCommand(std::wstring description);
	~ShowContentsCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};