#include "ShowFileSizeCommand.h"

ShowFileSizeCommand::ShowFileSizeCommand(IMenu* showFileSizeMenu)
{
	this->showFileSizeMenu = showFileSizeMenu;
}

std::wstring ShowFileSizeCommand::GetDescription() const
{
	return L"Show file size";
}

void ShowFileSizeCommand::Execute() const
{
	showFileSizeMenu->Start();
}