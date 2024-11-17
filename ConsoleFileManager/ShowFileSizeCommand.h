#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "ShowEnteredFileSizeCommand.h"
#include "ShowSelectedFileSizeCommand.h"

class ShowFileSizeCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};