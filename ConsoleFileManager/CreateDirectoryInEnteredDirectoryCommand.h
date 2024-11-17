#pragma once

#include <iostream>
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "DirectoriesWorker.h"
#include "ConsoleStringReader.h"
#include "StringSpacesChecker.h"

class CreateDirectoryInEnteredDirectoryCommand : public IMenuCommand
{
	IDirectoriesWorker* directoriesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	CreateDirectoryInEnteredDirectoryCommand();
	~CreateDirectoryInEnteredDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};