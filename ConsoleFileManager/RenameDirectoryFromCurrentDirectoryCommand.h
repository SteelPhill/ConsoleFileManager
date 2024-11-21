#pragma once

#include <iostream>
#include "IColoredTextWriter.h"
#include "IDirectoriesWorker.h"
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
#include "StringSpacesChecker.h"

class RenameDirectoryFromCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	std::wstring title;
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;
	IMenuSelector* menuSelector;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	RenameDirectoryFromCurrentDirectoryCommand(std::wstring description, std::wstring title);
	~RenameDirectoryFromCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};