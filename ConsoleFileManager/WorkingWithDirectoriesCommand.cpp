#include "WorkingWithDirectoriesCommand.h"

WorkingWithDirectoriesCommand::WorkingWithDirectoriesCommand(IMenu* workingWithDirectoriesMenu)
{
	this->workingWithDirectoriesMenu = workingWithDirectoriesMenu;
}

std::wstring WorkingWithDirectoriesCommand::GetDescription() const
{
	return L"Working with directories";
}

void WorkingWithDirectoriesCommand::Execute() const
{
	workingWithDirectoriesMenu->Start();
}