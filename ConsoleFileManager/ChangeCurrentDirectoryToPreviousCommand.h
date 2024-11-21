#pragma once

#include <iostream>
#include <filesystem>
#include "IMenuCommand.h"
#include "CurrentDirectory.h"

class ChangeCurrentDirectoryToPreviousCommand : public IMenuCommand
{
	std::wstring description;

public:
	ChangeCurrentDirectoryToPreviousCommand(std::wstring description);

	std::wstring GetDescription() const override;
	void Execute() const override;
};