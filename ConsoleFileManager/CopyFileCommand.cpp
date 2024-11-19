#include "CopyFileCommand.h"

CopyFileCommand::CopyFileCommand(IMenu* copyFileMenu)
{
	this->copyFileMenu = copyFileMenu;
}

std::wstring CopyFileCommand::GetDescription() const
{
	return L"Copy file";
}

void CopyFileCommand::Execute() const
{
	copyFileMenu->Start();
}