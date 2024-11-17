#include "RemoveDirectoryCommand.h"

std::wstring RemoveDirectoryCommand::GetDescription() const
{
	return L"Remove directory";
}

void RemoveDirectoryCommand::Execute() const
{
	IMenu* deleteDirectoryMenu = new ConsoleMenu(GetDescription() + L" options:");

	deleteDirectoryMenu->AddCommand(new RemoveDirectoryFromCurrentDirectoryCommand());
	deleteDirectoryMenu->AddCommand(new RemoveEnteredDirectoryCommand());

	deleteDirectoryMenu->Start();

	delete deleteDirectoryMenu;
}