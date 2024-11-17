#include "RemoveFileFromCurrentDirectoryCommand.h"

RemoveFileFromCurrentDirectoryCommand::RemoveFileFromCurrentDirectoryCommand()
{
	title = L"\tSelect file to be removed:";
	directoriesWorker = new DirectoriesWorker();
	filesWorker = new FilesWorker();
	menuSelector = new ConsoleMenuSelector();
}

RemoveFileFromCurrentDirectoryCommand::~RemoveFileFromCurrentDirectoryCommand()
{
	delete directoriesWorker;
	delete filesWorker;
	delete menuSelector;
}

std::wstring RemoveFileFromCurrentDirectoryCommand::GetDescription() const
{
	return L"Remove file from current directory";
}

void RemoveFileFromCurrentDirectoryCommand::Execute() const
{
	std::wstring fileToRemove = menuSelector->Select(title, directoriesWorker->GetFiles(CurrentDirectory::Path));

	if (fileToRemove.empty())
		return;

	fileToRemove.replace(0, Constants::ExplanatoryLineSize, L"");

	filesWorker->Remove(fileToRemove);
}