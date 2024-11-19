#include "CopyDirectoryCommand.h"

CopyDirectoryCommand::CopyDirectoryCommand(IMenu* copyDirectoryMenu)
{
	this->copyDirectoryMenu = copyDirectoryMenu;
}

std::wstring CopyDirectoryCommand::GetDescription() const
{
	return L"Copy directory";
}

void CopyDirectoryCommand::Execute() const
{
	copyDirectoryMenu->Start();
}