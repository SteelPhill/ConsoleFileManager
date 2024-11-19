#include "RemoveFileCommand.h"

RemoveFileCommand::RemoveFileCommand(IMenu* removeFileMenu)
{
	this->removeFileMenu = removeFileMenu;
}

std::wstring RemoveFileCommand::GetDescription() const
{
	return L"Remove file";
}

void RemoveFileCommand::Execute() const
{
	removeFileMenu->Start();
}