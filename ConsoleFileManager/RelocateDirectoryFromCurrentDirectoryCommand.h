#pragma once

#include <iostream>
#include "IColoredTextWriter.h"
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "IMenuSelector.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "DirectoriesWorker.h"
#include "ConsoleMenuSelector.h"
#include "ConsoleStringReader.h"
#include "ColoredTextConsoleWriter.h"
#include "StringSpacesChecker.h"
#include "Constants.h"
#include "CurrentDirectory.h"

class RelocateDirectoryFromCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	std::wstring title;
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;
	IMenuSelector* menuSelector;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	RelocateDirectoryFromCurrentDirectoryCommand(std::wstring description, std::wstring title);
	~RelocateDirectoryFromCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};