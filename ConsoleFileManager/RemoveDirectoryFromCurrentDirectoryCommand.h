#pragma once

#include <iostream>
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "ConsoleMenuSelector.h"
#include "Constants.h"
#include "CurrentDirectory.h"
#include "DirectoriesWorker.h"

class RemoveDirectoryFromCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	std::wstring title;
	IDirectoriesWorker* directoriesWorker;
	IMenuSelector* menuSelector;

public:
	RemoveDirectoryFromCurrentDirectoryCommand(std::wstring description, std::wstring title);
	~RemoveDirectoryFromCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};