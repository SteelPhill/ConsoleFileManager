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
	std::wstring description;
	IStringReader* stringReader;
	IStringSpacesChecker* spacesChecker;

public:
	ChangeCurrentDirectoryToEnteredCommand(std::wstring description);
	~ChangeCurrentDirectoryToEnteredCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};