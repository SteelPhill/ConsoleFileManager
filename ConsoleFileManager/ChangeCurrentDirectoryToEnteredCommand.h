#pragma once

#include <iostream>
#include <filesystem>
#include "IMenuCommand.h"
#include "IStringReader.h"
#include "IStringSpacesChecker.h"
#include "ConsoleStringReader.h"
#include "CurrentDirectory.h" 
#include "StringSpacesChecker.h"
namespace fs = std::filesystem;

class ChangeCurrentDirectoryToEnteredCommand : public IMenuCommand
{
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	ChangeCurrentDirectoryToEnteredCommand();
	~ChangeCurrentDirectoryToEnteredCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};