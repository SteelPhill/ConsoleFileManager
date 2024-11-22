#include "CreateDirectoryInEnteredDirectoryCommand.h"

CreateDirectoryInEnteredDirectoryCommand::CreateDirectoryInEnteredDirectoryCommand(std::wstring description)
{
	this->description = description;
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

CreateDirectoryInEnteredDirectoryCommand::~CreateDirectoryInEnteredDirectoryCommand()
{
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring CreateDirectoryInEnteredDirectoryCommand::GetDescription() const
{
	return description;
}

void CreateDirectoryInEnteredDirectoryCommand::Execute() const
{
	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	std::wcout << std::endl << "Enter new directory name" << std::endl << std::endl;
	std::wstring name = stringReader->Read();

	if (name.empty() || spacesChecker->Check(name))
		throw std::wstring(L"An empty line has been entered");

	directoriesWorker->Create(destinationDirectory, name);
}