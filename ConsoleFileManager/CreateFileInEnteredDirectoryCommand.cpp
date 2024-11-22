#include "CreateFileInEnteredDirectoryCommand.h"

CreateFileInEnteredDirectoryCommand::CreateFileInEnteredDirectoryCommand(std::wstring description)
{
	this->description = description;
	filesWorker = new FilesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

CreateFileInEnteredDirectoryCommand::~CreateFileInEnteredDirectoryCommand()
{
	delete filesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring CreateFileInEnteredDirectoryCommand::GetDescription() const
{
	return description;
}

void CreateFileInEnteredDirectoryCommand::Execute() const
{
	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	std::wcout << std::endl << "Enter new file name" << std::endl << std::endl;
	std::wstring name = stringReader->Read();

	if (name.empty() || spacesChecker->Check(name))
		throw std::wstring(L"An empty line has been entered");

	filesWorker->Create(destinationDirectory, name);
}