#pragma once

#include <iostream>
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "ConsoleMenuSelector.h"
#include "Constants.h"
#include "CurrentDirectory.h"
#include "DirectoriesWorker.h"

class ChangeCurrentDirectoryToSelectedCommand : public IMenuCommand
{
	std::wstring description;
	std::wstring title;
	IDirectoriesWorker* directoriesWorker;
	IMenuSelector* menuSelector;

public:
	ChangeCurrentDirectoryToSelectedCommand(std::wstring description, std::wstring title);
	~ChangeCurrentDirectoryToSelectedCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};