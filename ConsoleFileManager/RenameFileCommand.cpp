#include "RenameFileCommand.h"

RenameFileCommand::RenameFileCommand(IMenu* renameFileMenu)
{
	this->renameFileMenu = renameFileMenu;
}

std::wstring RenameFileCommand::GetDescription() const
{
	return L"Rename file";
}

void RenameFileCommand::Execute() const
{
	renameFileMenu->Start();
}