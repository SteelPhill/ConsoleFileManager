#pragma once

#include <iostream>
#include "IDirectoryContentWriter.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ConsoleStringReader.h"
#include "DirectoryContentConsoleWriter.h"
#include "StringSpacesChecker.h"

class ShowContentsEnteredDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	IDirectoryContentWriter* contentWriter;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	ShowContentsEnteredDirectoryCommand(std::wstring description);
	~ShowContentsEnteredDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};