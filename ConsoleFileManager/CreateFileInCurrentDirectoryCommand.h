#pragma once

#include <iostream>
#include "IFilesWorker.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ConsoleStringReader.h"
#include "CurrentDirectory.h"
#include "FilesWorker.h"
#include "StringSpacesChecker.h"

class CreateFileInCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	IFilesWorker* filesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	CreateFileInCurrentDirectoryCommand(std::wstring description);
	~CreateFileInCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};