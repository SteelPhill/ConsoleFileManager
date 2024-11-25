#pragma once

#include <iostream>
#include "IColoredTextWriter.h"
#include "IDirectoriesWorker.h"
#include "IMenuCommand.h"
#include "ColoredTextConsoleWriter.h"
#include "Constants.h"
#include "CurrentDirectory.h"
#include "DirectoriesWorker.h"

class ShowCurrentDirectorySizeCommand : public IMenuCommand
{
	std::wstring description;
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;

public:
	ShowCurrentDirectorySizeCommand(std::wstring description);
	~ShowCurrentDirectorySizeCommand();

	std::wstring GetDescription() const override;
	void Execute() const override;
};