#pragma once

#include <iostream>
#include "IColoredTextWriter.h"
#include "IDirectoriesWorker.h"
#include "IFilesWorker.h"
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ColoredTextConsoleWriter.h"
#include "ConsoleMenuSelector.h"
#include "ConsoleStringReader.h"
#include "Constants.h"
#include "CurrentDirectory.h"
#include "DirectoriesWorker.h"
#include "FilesWorker.h"
#include "StringSpacesChecker.h"

class CopyFileFromCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	std::wstring title;
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;
	IFilesWorker* filesWorker;
	IMenuSelector* menuSelector;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	CopyFileFromCurrentDirectoryCommand(std::wstring description, std::wstring title);
	~CopyFileFromCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};