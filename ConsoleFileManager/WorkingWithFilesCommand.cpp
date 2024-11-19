#include "WorkingWithFilesCommand.h"

WorkingWithFilesCommand::WorkingWithFilesCommand(IMenu* workingWithFilesMenu)
{
	this->workingWithFilesMenu = workingWithFilesMenu;
}

std::wstring WorkingWithFilesCommand::GetDescription() const
{
	return L"Working with files";
}

void WorkingWithFilesCommand::Execute() const
{
	workingWithFilesMenu->Start();
}