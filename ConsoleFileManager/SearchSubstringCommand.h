#pragma once

#include <iostream>
#include "IMenuCommand.h"
#include "ConsoleMenu.h"
#include "SubstringInCurrentAndNestedDirectoriesCommand.h"
#include "SubstringInEnteredAndNestedDirectoriesCommand.h"
#include "SubstringInOnlyCurrentDirectoryCommand.h"
#include "SubstringInOnlyEnteredDirectoryCommand.h"

class SearchSubstringCommand : public IMenuCommand
{
public:
	std::wstring GetDescription() const override;
	void Execute() const override;
};