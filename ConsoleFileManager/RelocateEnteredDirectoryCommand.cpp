#include "RelocateEnteredDirectoryCommand.h"

RelocateEnteredDirectoryCommand::RelocateEnteredDirectoryCommand(std::wstring description)
{
	this->description = description;
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RelocateEnteredDirectoryCommand::~RelocateEnteredDirectoryCommand()
{
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RelocateEnteredDirectoryCommand::GetDescription() const
{
	return description;
}

void RelocateEnteredDirectoryCommand::Execute() const
{
	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter directory path to be relocated" << std::endl << std::endl;
	std::wstring directoryToRelocate = stringReader->Read();

	if (directoryToRelocate.empty() || spacesChecker->Check(directoryToRelocate))
		throw std::wstring(L"An empty line has been entered");

	if (directoryToRelocate.find(L"\\") == std::wstring::npos)
		directoryToRelocate += L"\\";

	std::wcout << std::endl << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	directoriesWorker->Relocate(directoryToRelocate, destinationDirectory);
}