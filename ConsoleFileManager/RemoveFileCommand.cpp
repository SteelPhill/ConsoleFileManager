#include "RemoveFileCommand.h"

std::wstring RemoveFileCommand::GetDescription() const
{
	return L"Remove file";
}

void RemoveFileCommand::Execute() const
{
	IMenu* deleteFileMenu = new ConsoleMenu(GetDescription() + L" options:");

	deleteFileMenu->AddCommand(new RemoveFileFromCurrentDirectoryCommand());
	deleteFileMenu->AddCommand(new RemoveEnteredFileCommand());

	deleteFileMenu->Start();

	delete deleteFileMenu;
}