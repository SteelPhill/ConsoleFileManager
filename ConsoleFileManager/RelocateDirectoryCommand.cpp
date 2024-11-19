#include "RelocateDirectoryCommand.h"

RelocateDirectoryCommand::RelocateDirectoryCommand(IMenu* relocateDirectoryMenu)
{
	this->relocateDirectoryMenu = relocateDirectoryMenu;
}

std::wstring RelocateDirectoryCommand::GetDescription() const
{
	return L"Relocate directory";
}

void RelocateDirectoryCommand::Execute() const
{
	relocateDirectoryMenu->Start();
}