#pragma once

#include <iostream>
#include <vector>
#include "IColoredTextWriter.h"
#include "IDirectoryContentWriter.h"
#include "ColoredTextConsoleWriter.h"
#include "Constants.h"
#include "DirectoriesWorker.h"

class DirectoryContentConsoleWriter : public IDirectoryContentWriter
{
	IColoredTextWriter* coloredTextWriter;
	IDirectoriesWorker* directoriesWorker;

public:
	DirectoryContentConsoleWriter();
	~DirectoryContentConsoleWriter();

	void Write(const std::wstring& directory) const override;
};