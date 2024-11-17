#include "CreateDirectoryCommand.h"

std::wstring CreateDirectoryCommand::GetDescription() const
{
	return L"Create directory";
}

void CreateDirectoryCommand::Execute() const
{
	IMenu* createDirectoryMenu = new ConsoleMenu(GetDescription() + L" options:");

	createDirectoryMenu->AddCommand(new CreateDirectoryInCurrentDirectoryCommand());
	createDirectoryMenu->AddCommand(new CreateDirectoryInEnteredDirectoryCommand());

	createDirectoryMenu->Start();

	delete createDirectoryMenu;
}