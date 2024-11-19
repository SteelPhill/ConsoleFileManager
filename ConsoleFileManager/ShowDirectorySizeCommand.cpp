#include "ShowDirectorySizeCommand.h"

ShowDirectorySizeCommand::ShowDirectorySizeCommand(IMenu* showDirectorySizeMenu)
{
	this->showDirectorySizeMenu = showDirectorySizeMenu;
}

std::wstring ShowDirectorySizeCommand::GetDescription() const
{
	return L"Show directory size";
}

void ShowDirectorySizeCommand::Execute() const
{
	showDirectorySizeMenu->Start();
}