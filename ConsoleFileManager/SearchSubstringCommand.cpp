#include "SearchSubstringCommand.h"

SearchSubstringCommand::SearchSubstringCommand(IMenu* searchSubstringMenu)
{
	this->searchSubstringMenu = searchSubstringMenu;
}

std::wstring SearchSubstringCommand::GetDescription() const
{
	return L"Search substring";
}

void SearchSubstringCommand::Execute() const
{
	searchSubstringMenu->Start();
}