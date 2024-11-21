#include "ChangeCurrentDirectoryToSelectedCommand.h"

ChangeCurrentDirectoryToSelectedCommand::ChangeCurrentDirectoryToSelectedCommand(std::wstring description, std::wstring title)
{
	this->description = description;
	this->title = title;
	directoriesWorker = new DirectoriesWorker();
	menuSelector = new ConsoleMenuSelector();
}

ChangeCurrentDirectoryToSelectedCommand::~ChangeCurrentDirectoryToSelectedCommand()
{
	delete directoriesWorker;
	delete menuSelector;
}

std::wstring ChangeCurrentDirectoryToSelectedCommand::GetDescription() const
{
	return description;
}

void ChangeCurrentDirectoryToSelectedCommand::Execute() const
{
	std::wstring newCurrentDirectory = menuSelector->Select(title, directoriesWorker->GetDirectories(CurrentDirectory::Path));

	if (newCurrentDirectory.empty())
		return;

	newCurrentDirectory.replace(0, Constants::ExplanatoryLineSize, L"");

	CurrentDirectory::Path = newCurrentDirectory;
}