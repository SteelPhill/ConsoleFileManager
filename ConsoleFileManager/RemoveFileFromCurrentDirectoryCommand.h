#pragma once

#include <iostream>
#include "IDirectoriesWorker.h"
#include "IFilesWorker.h"
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "ConsoleMenuSelector.h"
#include "Constants.h"
#include "CurrentDirectory.h"
#include "DirectoriesWorker.h"
#include "FilesWorker.h"

class RemoveFileFromCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	std::wstring title;
	IDirectoriesWorker* directoriesWorker;
	IFilesWorker* filesWorker;
	IMenuSelector* menuSelector;

public:
	RemoveFileFromCurrentDirectoryCommand(std::wstring description, std::wstring title);
	~RemoveFileFromCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};