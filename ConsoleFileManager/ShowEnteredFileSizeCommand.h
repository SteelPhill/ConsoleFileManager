#pragma once

#include <iostream>
#include "IColoredTextWriter.h"
#include "IFilesWorker.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ColoredTextConsoleWriter.h"
#include "ConsoleStringReader.h"
#include "Constants.h"
#include "FilesWorker.h"
#include "StringSpacesChecker.h"

class ShowEnteredFileSizeCommand : public IMenuCommand
{
	std::wstring description;
	IColoredTextWriter* coloredTextWriter;
	IFilesWorker* filesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spaceChecker;

public:
	ShowEnteredFileSizeCommand(std::wstring description);
	~ShowEnteredFileSizeCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};