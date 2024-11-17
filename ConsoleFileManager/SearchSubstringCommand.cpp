#include "SearchSubstringCommand.h"

std::wstring SearchSubstringCommand::GetDescription() const
{
	return L"Search substring";
}

void SearchSubstringCommand::Execute() const
{
	IMenu* searchSubstringMenu = new ConsoleMenu(GetDescription() + L" options:");

	searchSubstringMenu->AddCommand(new SubstringInOnlyCurrentDirectoryCommand());
	searchSubstringMenu->AddCommand(new SubstringInCurrentAndNestedDirectoriesCommand());
	searchSubstringMenu->AddCommand(new SubstringInOnlyEnteredDirectoryCommand());
	searchSubstringMenu->AddCommand(new SubstringInEnteredAndNestedDirectoriesCommand());

	searchSubstringMenu->Start();

	delete searchSubstringMenu;
}