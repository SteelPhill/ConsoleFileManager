#pragma once

#include <iostream>
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ConsoleStringReader.h"
#include "DirectoriesWorker.h"
#include "StringSpacesChecker.h"

class CopyEnteredDirectoryCommand : public IMenuCommand
{
	IDirectoriesWorker* directoriesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	CopyEnteredDirectoryCommand();
	~CopyEnteredDirectoryCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};