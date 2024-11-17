#include "ChangeCurrentDirectoryCommand.h"

std::wstring ChangeCurrentDirectoryCommand::GetDescription() const
{
	return L"Change current directory";
}

void ChangeCurrentDirectoryCommand::Execute() const
{
	IMenu* changeCurrentDirectoryMenu = new ConsoleMenu(GetDescription() + L" options:");

	changeCurrentDirectoryMenu->AddCommand(new ChangeCurrentDirectoryToPreviousCommand());
	changeCurrentDirectoryMenu->AddCommand(new ChangeCurrentDirectoryToSelectedCommand());
	changeCurrentDirectoryMenu->AddCommand(new ChangeCurrentDirectoryToEnteredCommand());

	changeCurrentDirectoryMenu->Start();

	delete changeCurrentDirectoryMenu;
}