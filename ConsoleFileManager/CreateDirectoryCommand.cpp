#include "CreateDirectoryCommand.h"

CreateDirectoryCommand::CreateDirectoryCommand(IMenu* createDirectoryMenu)
{
	this->createDirectoryMenu = createDirectoryMenu;
}

std::wstring CreateDirectoryCommand::GetDescription() const
{
	return L"Create directory";
}

void CreateDirectoryCommand::Execute() const
{
	createDirectoryMenu->Start();
}