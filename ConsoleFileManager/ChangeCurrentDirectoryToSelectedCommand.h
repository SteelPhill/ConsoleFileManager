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
	std::wstring title;
	IDirectoriesWorker* directoriesWorker;
	IMenuSelector* menuSelector;

public:
	ChangeCurrentDirectoryToSelectedCommand();
	~ChangeCurrentDirectoryToSelectedCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};