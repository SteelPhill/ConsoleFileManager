#pragma once

#include <iostream>
#include "IColoredTextWriter.h"
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ColoredTextConsoleWriter.h"
#include "ConsoleStringReader.h"
#include "Constants.h"
#include "CurrentDirectory.h"
#include "DirectoriesWorker.h"
#include "StringSpacesChecker.h"

class SubstringInOnlyCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	SubstringInOnlyCurrentDirectoryCommand(std::wstring description);
	~SubstringInOnlyCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};