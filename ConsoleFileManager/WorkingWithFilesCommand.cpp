#include "WorkingWithFilesCommand.h"

std::wstring WorkingWithFilesCommand::GetDescription() const
{
	return L"Working with files";
}

void WorkingWithFilesCommand::Execute() const
{
	IMenu* workingWithFilesMenu = new ConsoleMenu(GetDescription() + L" options:");

	workingWithFilesMenu->AddCommand(new ShowFileSizeCommand());
	workingWithFilesMenu->AddCommand(new CreateFileCommand());
	workingWithFilesMenu->AddCommand(new CopyFileCommand());
	workingWithFilesMenu->AddCommand(new RelocateFileCommand());
	workingWithFilesMenu->AddCommand(new RenameFileCommand());
	workingWithFilesMenu->AddCommand(new RemoveFileCommand());

	workingWithFilesMenu->Start();

	delete workingWithFilesMenu;
}