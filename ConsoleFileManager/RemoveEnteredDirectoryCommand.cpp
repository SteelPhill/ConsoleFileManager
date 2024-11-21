#include "RemoveEnteredDirectoryCommand.h"

RemoveEnteredDirectoryCommand::RemoveEnteredDirectoryCommand(std::wstring description)
{
	this->description = description;
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RemoveEnteredDirectoryCommand::~RemoveEnteredDirectoryCommand()
{
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RemoveEnteredDirectoryCommand::GetDescription() const
{
	return description;
}

void RemoveEnteredDirectoryCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter directory path to be removed" << std::endl << std::endl;
	std::wstring directoryToRemove = stringReader->Read();

	if (directoryToRemove.empty() || spacesChecker->Check(directoryToRemove))
		throw std::wstring(L"An empty line has been entered");

	if (directoryToRemove.find(L"\\") == std::wstring::npos)
		directoryToRemove += L"\\";

	directoriesWorker->Remove(directoryToRemove);
}