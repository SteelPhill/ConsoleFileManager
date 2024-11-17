#include "CreateDirectoryInCurrentDirectoryCommand.h"

CreateDirectoryInCurrentDirectoryCommand::CreateDirectoryInCurrentDirectoryCommand()
{
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
	return L"Create directory in current directory";
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