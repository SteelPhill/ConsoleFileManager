#pragma once

#include <iostream>
#include <filesystem>
#include "IMenuCommand.h"
#include "CurrentDirectory.h"

class ChangeCurrentDirectoryToPreviousCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};