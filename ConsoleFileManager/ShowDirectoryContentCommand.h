#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "ShowContentsCurrentDirectoryCommand.h"
#include "ShowContentsEnteredDirectoryCommand.h"

class ShowDirectoryContentCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};