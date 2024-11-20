#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class SubmenuExecuterCommand : public IMenuCommand
{
	IMenu* submenu;
	std::wstring description;

public:
	SubmenuExecuterCommand(IMenu* submenu, std::wstring description);

	std::wstring GetDescription() const;
	void Execute() const;
};