#include "CopyFileCommand.h"

std::wstring CopyFileCommand::GetDescription() const
{
	return L"Copy file";
}

void CopyFileCommand::Execute() const
{
	IMenu* copyFileMenu = new ConsoleMenu(GetDescription() + L" options:");

	copyFileMenu->AddCommand(new CopyFileFromCurrentDirectoryCommand());
	copyFileMenu->AddCommand(new CopyEnteredFileCommand());

	copyFileMenu->Start();

	delete copyFileMenu;
}