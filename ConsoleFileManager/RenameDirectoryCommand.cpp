#include "RenameDirectoryCommand.h"

RenameDirectoryCommand::RenameDirectoryCommand(IMenu* renameDirectoryMenu)
{
	this->renameDirectoryMenu = renameDirectoryMenu;
}

std::wstring RenameDirectoryCommand::GetDescription() const
{
	return L"Rename directory";
}

void RenameDirectoryCommand::Execute() const
{
	renameDirectoryMenu->Start();
}