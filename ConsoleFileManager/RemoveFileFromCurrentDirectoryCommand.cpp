#include "RemoveFileFromCurrentDirectoryCommand.h"

RemoveFileFromCurrentDirectoryCommand::RemoveFileFromCurrentDirectoryCommand(std::wstring description, std::wstring title)
{
	this->description = description;
	this->title = title;
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
	return description;
}

void RemoveFileFromCurrentDirectoryCommand::Execute() const
{
	std::wstring fileToRemove = menuSelector->Select(title, directoriesWorker->GetFiles(CurrentDirectory::Path));

	if (fileToRemove.empty())
		return;

	fileToRemove.replace(0, Constants::ExplanatoryLineSize, L"");

	filesWorker->Remove(fileToRemove);
}