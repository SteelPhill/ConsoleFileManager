#include "RemoveDirectoryFromCurrentDirectoryCommand.h"

RemoveDirectoryFromCurrentDirectoryCommand::RemoveDirectoryFromCurrentDirectoryCommand(std::wstring description, std::wstring title)
{
	this->description = description;
	this->title = title;
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
	return description;
}

void RemoveDirectoryFromCurrentDirectoryCommand::Execute() const
{
	std::wstring directoryToRemove = menuSelector->Select(title, directoriesWorker->GetDirectories(CurrentDirectory::Path));

	if (directoryToRemove.empty())
		return;

	directoryToRemove.replace(0, Constants::ExplanatoryLineSize, L"");

	directoriesWorker->Remove(directoryToRemove);
}