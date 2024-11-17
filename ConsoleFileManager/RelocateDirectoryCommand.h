#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "RelocateDirectoryFromCurrentDirectoryCommand.h"
#include "RelocateEnteredDirectoryCommand.h"

class RelocateDirectoryCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};