#include "CreateFileCommand.h"

std::wstring CreateFileCommand::GetDescription() const
{
	return L"Create file";
}

void CreateFileCommand::Execute() const
{
	IMenu* createFileMenu = new ConsoleMenu(GetDescription() + L" options:");

	createFileMenu->AddCommand(new CreateFileInCurrentDirectoryCommand());
	createFileMenu->AddCommand(new CreateFileInEnteredDirectoryCommand());

	createFileMenu->Start();

	delete createFileMenu;
}