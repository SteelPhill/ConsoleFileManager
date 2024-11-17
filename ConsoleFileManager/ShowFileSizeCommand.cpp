#include "ShowFileSizeCommand.h"

std::wstring ShowFileSizeCommand::GetDescription() const
{
	return L"Show file size";
}

void ShowFileSizeCommand::Execute() const
{
	IMenu* showFileSizeMenu = new ConsoleMenu(GetDescription() + L" options:");

	showFileSizeMenu->AddCommand(new ShowSelectedFileSizeCommand());
	showFileSizeMenu->AddCommand(new ShowEnteredFileSizeCommand());

	showFileSizeMenu->Start();

	delete showFileSizeMenu;
}