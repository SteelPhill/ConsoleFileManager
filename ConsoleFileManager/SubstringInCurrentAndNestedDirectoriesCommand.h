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

class SubstringInCurrentAndNestedDirectoriesCommand : public IMenuCommand
{
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	SubstringInCurrentAndNestedDirectoriesCommand();
	~SubstringInCurrentAndNestedDirectoriesCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};