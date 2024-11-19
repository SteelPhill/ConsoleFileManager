#include "ShowDirectoryContentCommand.h"

ShowDirectoryContentCommand::ShowDirectoryContentCommand(IMenu* showDirectoryContentMenu)
{
	this->showDirectoryContentMenu = showDirectoryContentMenu;
}

std::wstring ShowDirectoryContentCommand::GetDescription() const
{
	return L"Show directory content";
}

void ShowDirectoryContentCommand::Execute() const
{
	showDirectoryContentMenu->Start();
}