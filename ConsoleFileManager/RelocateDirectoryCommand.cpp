#include "RelocateDirectoryCommand.h"

std::wstring RelocateDirectoryCommand::GetDescription() const
{
	return L"Relocate directory";
}

void RelocateDirectoryCommand::Execute() const
{
	IMenu* relocateDirectoryMenu = new ConsoleMenu(GetDescription() + L" options:");

	relocateDirectoryMenu->AddCommand(new RelocateDirectoryFromCurrentDirectoryCommand());
	relocateDirectoryMenu->AddCommand(new RelocateEnteredDirectoryCommand());

	relocateDirectoryMenu->Start();

	delete relocateDirectoryMenu;
}