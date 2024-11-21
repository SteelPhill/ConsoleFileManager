#pragma once

#include <iostream>
#include "IColoredTextWriter.h"
#include "IDirectoriesWorker.h"
#include "IFilesWorker.h"
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "FilesWorker.h"
#include "ColoredTextConsoleWriter.h"
#include "ConsoleMenuSelector.h"
#include "Constants.h"
#include "CurrentDirectory.h"
#include "DirectoriesWorker.h"

class ShowSelectedFileSizeCommand : public IMenuCommand
{
	std::wstring description;
	std::wstring title;
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;
	IFilesWorker* filesWorker;
	IMenuSelector* menuSelector;

public:
	ShowSelectedFileSizeCommand(std::wstring description, std::wstring title);
	~ShowSelectedFileSizeCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};