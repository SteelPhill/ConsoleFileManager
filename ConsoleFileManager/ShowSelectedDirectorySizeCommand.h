#pragma once

#include <iostream>
#include "IColoredTextWriter.h"
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "DirectoriesWorker.h"
#include "ConsoleMenuSelector.h"
#include "ColoredTextConsoleWriter.h"
#include "Constants.h"
#include "CurrentDirectory.h"

class ShowSelectedDirectorySizeCommand : public IMenuCommand
{
	std::wstring title;
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;
	IMenuSelector* menuSelector;

public:
	ShowSelectedDirectorySizeCommand();
	~ShowSelectedDirectorySizeCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};