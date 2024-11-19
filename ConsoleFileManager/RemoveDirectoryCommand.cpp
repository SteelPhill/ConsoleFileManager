#include "RemoveDirectoryCommand.h"

RemoveDirectoryCommand::RemoveDirectoryCommand(IMenu* removeDirectoryMenu)
{
	this->removeDirectoryMenu = removeDirectoryMenu;
}

std::wstring RemoveDirectoryCommand::GetDescription() const
{
	return L"Remove directory";
}

void RemoveDirectoryCommand::Execute() const
{
	removeDirectoryMenu->Start();
}