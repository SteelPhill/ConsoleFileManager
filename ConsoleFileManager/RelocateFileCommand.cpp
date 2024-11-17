#include "RelocateFileCommand.h"

std::wstring RelocateFileCommand::GetDescription() const
{
	return L"Relocate file";
}

void RelocateFileCommand::Execute() const
{
	IMenu* relocateFileMenu = new ConsoleMenu(GetDescription() + L" options:");

	relocateFileMenu->AddCommand(new RelocateFileFromCurrentDirectoryCommand());
	relocateFileMenu->AddCommand(new RelocateEnteredFileCommand());

	relocateFileMenu->Start();

	delete relocateFileMenu;
}