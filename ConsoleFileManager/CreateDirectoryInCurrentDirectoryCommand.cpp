#include "CreateDirectoryInCurrentDirectoryCommand.h"

CreateDirectoryInCurrentDirectoryCommand::CreateDirectoryInCurrentDirectoryCommand(std::wstring description)
{
	this->description = description;
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

CreateDirectoryInCurrentDirectoryCommand::~CreateDirectoryInCurrentDirectoryCommand()
{
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring CreateDirectoryInCurrentDirectoryCommand::GetDescription() const
{
	return description;
}

void CreateDirectoryInCurrentDirectoryCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter new directory name" << std::endl << std::endl;
	std::wstring name = stringReader->Read();

	if (name.empty() || spacesChecker->Check(name))
		throw std::wstring(L"An empty line has been entered");

	directoriesWorker->Create(CurrentDirectory::Path, name);
}