#include "ChangeCurrentDirectoryToSelectedCommand.h"

ChangeCurrentDirectoryToSelectedCommand::ChangeCurrentDirectoryToSelectedCommand()
{
	title = L"\tSelect new current directory:";
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
	return L"Change current directory to selected";
}

void ChangeCurrentDirectoryToSelectedCommand::Execute() const
{
	std::wstring newCurrentDirectory = menuSelector->Select(title, directoriesWorker->GetDirectories(CurrentDirectory::Path));

	if (newCurrentDirectory.empty())
		return;

	newCurrentDirectory.replace(0, Constants::ExplanatoryLineSize, L"");

	CurrentDirectory::Path = newCurrentDirectory;
}