#include "CreateFileCommand.h"

CreateFileCommand::CreateFileCommand(IMenu* createFileMenu)
{
	this->createFileMenu = createFileMenu;
}

std::wstring CreateFileCommand::GetDescription() const
{
	return L"Create file";
}

void CreateFileCommand::Execute() const
{
	createFileMenu->Start();
}