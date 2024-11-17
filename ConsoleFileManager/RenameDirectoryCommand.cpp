#include "RenameDirectoryCommand.h"

std::wstring RenameDirectoryCommand::GetDescription() const
{
	return L"Rename directory";
}

void RenameDirectoryCommand::Execute() const
{
	IMenu* renameDirectoryMenu = new ConsoleMenu(GetDescription() + L" options:");

	renameDirectoryMenu->AddCommand(new RenameDirectoryFromCurrentDirectoryCommand());
	renameDirectoryMenu->AddCommand(new RenameEnteredDirectoryCommand());

	renameDirectoryMenu->Start();

	delete renameDirectoryMenu;
}