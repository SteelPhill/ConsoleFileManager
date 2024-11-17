#include "RemoveDirectoryFromCurrentDirectoryCommand.h"

RemoveDirectoryFromCurrentDirectoryCommand::RemoveDirectoryFromCurrentDirectoryCommand()
{
	title = L"\tSelect directory to be removed:";
	directoriesWorker = new DirectoriesWorker();
	menuSelector = new ConsoleMenuSelector();
}

RemoveDirectoryFromCurrentDirectoryCommand::~RemoveDirectoryFromCurrentDirectoryCommand()
{
	delete directoriesWorker;
	delete menuSelector;
}

std::wstring RemoveDirectoryFromCurrentDirectoryCommand::GetDescription() const
{
	return L"Remove directory from current directory";
}

void RemoveDirectoryFromCurrentDirectoryCommand::Execute() const
{
	std::wstring directoryToRemove = menuSelector->Select(title, directoriesWorker->GetDirectories(CurrentDirectory::Path));

	if (directoryToRemove.empty())
		return;

	directoryToRemove.replace(0, Constants::ExplanatoryLineSize, L"");

	directoriesWorker->Remove(directoryToRemove);
}