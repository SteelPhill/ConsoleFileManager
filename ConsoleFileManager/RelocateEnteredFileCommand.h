#pragma once

#include <iostream>
#include "IFilesWorker.h"
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "FilesWorker.h"
#include "ConsoleStringReader.h"
#include "StringSpacesChecker.h"

class RelocateEnteredFileCommand : public IMenuCommand
{
	std::wstring description;
	IFilesWorker* filesWorker;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	RelocateEnteredFileCommand(std::wstring description);
	~RelocateEnteredFileCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};