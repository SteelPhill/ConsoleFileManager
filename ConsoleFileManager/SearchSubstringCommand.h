#pragma once

#include <iostream>
#include "IMenu.h"
#include "IMenuCommand.h"

class SearchSubstringCommand : public IMenuCommand
{
	IMenu* searchSubstringMenu;

public:
	SearchSubstringCommand(IMenu* searchSubstringMenu);

	std::wstring GetDescription() const override;
	void Execute() const override;
};