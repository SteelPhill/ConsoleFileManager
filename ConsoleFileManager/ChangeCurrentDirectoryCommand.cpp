#include "ChangeCurrentDirectoryCommand.h"

ChangeCurrentDirectoryCommand::ChangeCurrentDirectoryCommand(IMenu* changeCurrentDirectoryMenu)
{
	this->changeCurrentDirectoryMenu = changeCurrentDirectoryMenu;
}

std::wstring ChangeCurrentDirectoryCommand::GetDescription() const
{
	return L"Change current directory";
}

void ChangeCurrentDirectoryCommand::Execute() const
{
	changeCurrentDirectoryMenu->Start();
}