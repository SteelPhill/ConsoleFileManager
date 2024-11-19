#include "RelocateFileCommand.h"

RelocateFileCommand::RelocateFileCommand(IMenu* relocateFileMenu)
{
	this->relocateFileMenu = relocateFileMenu;
}

std::wstring RelocateFileCommand::GetDescription() const
{
	return L"Relocate file";
}

void RelocateFileCommand::Execute() const
{
	relocateFileMenu->Start();
}