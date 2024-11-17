#include "CopyDirectoryCommand.h"

std::wstring CopyDirectoryCommand::GetDescription() const
{
	return L"Copy directory";
}

void CopyDirectoryCommand::Execute() const
{
	IMenu* copyDirectoryMenu = new ConsoleMenu(GetDescription() + L" options:");

	copyDirectoryMenu->AddCommand(new CopyDirectoryFromCurrentDirectoryCommand());
	copyDirectoryMenu->AddCommand(new CopyEnteredDirectoryCommand());

	copyDirectoryMenu->Start();

	delete copyDirectoryMenu;
}