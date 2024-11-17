#include "WorkingWithDirectoriesCommand.h"

std::wstring WorkingWithDirectoriesCommand::GetDescription() const
{
	return L"Working with directories";
}

void WorkingWithDirectoriesCommand::Execute() const
{
	IMenu* workingWithDirectoriesMenu = new ConsoleMenu(GetDescription() + L" options:");

	workingWithDirectoriesMenu->AddCommand(new ShowDirectorySizeCommand());
	workingWithDirectoriesMenu->AddCommand(new CreateDirectoryCommand());
	workingWithDirectoriesMenu->AddCommand(new CopyDirectoryCommand());
	workingWithDirectoriesMenu->AddCommand(new RelocateDirectoryCommand());
	workingWithDirectoriesMenu->AddCommand(new RenameDirectoryCommand());
	workingWithDirectoriesMenu->AddCommand(new RemoveDirectoryCommand());

	workingWithDirectoriesMenu->Start();

	delete workingWithDirectoriesMenu;
}