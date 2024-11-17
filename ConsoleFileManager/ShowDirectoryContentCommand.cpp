#include "ShowDirectoryContentCommand.h"

std::wstring ShowDirectoryContentCommand::GetDescription() const
{
	return L"Show directory content";
}

void ShowDirectoryContentCommand::Execute() const
{
	IMenu* showDirectoryContentMenu = new ConsoleMenu(GetDescription() + L" options:");

	showDirectoryContentMenu->AddCommand(new ShowContentsCurrentDirectoryCommand());
	showDirectoryContentMenu->AddCommand(new ShowContentsEnteredDirectoryCommand());

	showDirectoryContentMenu->Start();

	delete showDirectoryContentMenu;
}