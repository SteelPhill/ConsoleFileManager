#pragma once

#include <iostream>
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ConsoleStringReader.h"
#include "CurrentDirectory.h"
#include "DirectoriesWorker.h"
#include "StringSpacesChecker.h"

class CreateDirectoryInCurrentDirectoryCommand : public IMenuCommand
{
	std::wstring description;
	IDirectoriesWorker* directoriesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	CreateDirectoryInCurrentDirectoryCommand(std::wstring description);
	~CreateDirectoryInCurrentDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};