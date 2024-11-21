#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class SubmenuExecuterCommand : public IMenuCommand
{
	std::wstring description;
	IMenu* submenu;

public:
	SubmenuExecuterCommand(std::wstring description, IMenu* submenu);

	std::wstring GetDescription() const;
	void Execute() const;
};