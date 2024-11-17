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
	IDirectoryContentWriter* contentWriter;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	ShowContentsEnteredDirectoryCommand();
	~ShowContentsEnteredDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};