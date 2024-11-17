#include "ShowDirectorySizeCommand.h"

std::wstring ShowDirectorySizeCommand::GetDescription() const
{
	return L"Show directory size";
}

void ShowDirectorySizeCommand::Execute() const
{
	IMenu* showDirectorySizeMenu = new ConsoleMenu(GetDescription() + L" options:");

	showDirectorySizeMenu->AddCommand(new ShowCurrentDirectorySizeCommand());
	showDirectorySizeMenu->AddCommand(new ShowSelectedDirectorySizeCommand());
	showDirectorySizeMenu->AddCommand(new ShowEnteredDirectorySizeCommand());

	showDirectorySizeMenu->Start();

	delete showDirectorySizeMenu;
}