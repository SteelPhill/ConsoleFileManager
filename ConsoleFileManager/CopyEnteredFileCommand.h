#pragma once

#include <iostream>
#include "IFilesWorker.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ConsoleStringReader.h"
#include "FilesWorker.h"
#include "StringSpacesChecker.h"

class CopyEnteredFileCommand : public IMenuCommand
{
	IFilesWorker* filesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	CopyEnteredFileCommand();
	~CopyEnteredFileCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};