#include "RenameFileCommand.h"

std::wstring RenameFileCommand::GetDescription() const
{
	return L"Rename file";
}

void RenameFileCommand::Execute() const
{
	IMenu* renameFileMenu = new ConsoleMenu(GetDescription() + L" options:");

	renameFileMenu->AddCommand(new RenameFileFromCurrentDirectoryCommand());
	renameFileMenu->AddCommand(new RenameEnteredFileCommand());

	renameFileMenu->Start();

	delete renameFileMenu;
}