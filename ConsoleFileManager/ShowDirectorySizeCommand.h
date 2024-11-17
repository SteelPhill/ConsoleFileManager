#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "ShowCurrentDirectorySizeCommand.h"
#include "ShowEnteredDirectorySizeCommand.h"
#include "ShowSelectedDirectorySizeCommand.h"

class ShowDirectorySizeCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};