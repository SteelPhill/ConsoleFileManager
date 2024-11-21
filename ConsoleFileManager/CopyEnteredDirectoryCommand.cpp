#include "CopyEnteredDirectoryCommand.h"

CopyEnteredDirectoryCommand::CopyEnteredDirectoryCommand(std::wstring description)
{
	this->description = description;
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

CopyEnteredDirectoryCommand::~CopyEnteredDirectoryCommand()
{
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring CopyEnteredDirectoryCommand::GetDescription() const
{
	return description;
}

void CopyEnteredDirectoryCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter directory path to be copied" << std::endl << std::endl;
	std::wstring directoryToCopy = stringReader->Read();

	if (directoryToCopy.empty() || spacesChecker->Check(directoryToCopy))
		throw std::wstring(L"An empty line has been entered");

	if (directoryToCopy.find(L"\\") == std::wstring::npos)
		directoryToCopy += L"\\";

	std::wcout << std::endl << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	directoriesWorker->Copy(directoryToCopy, destinationDirectory);
}