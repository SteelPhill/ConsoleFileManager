#include "CreateFileInCurrentDirectoryCommand.h"

CreateFileInCurrentDirectoryCommand::CreateFileInCurrentDirectoryCommand(std::wstring description)
{
	this->description = description;
	filesWorker = new FilesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

CreateFileInCurrentDirectoryCommand::~CreateFileInCurrentDirectoryCommand()
{
	delete filesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring CreateFileInCurrentDirectoryCommand::GetDescription() const
{
	return description;
}

void CreateFileInCurrentDirectoryCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter new file name" << std::endl << std::endl;
	std::wstring name = stringReader->Read();

	if (name.empty() || spacesChecker->Check(name))
		throw std::wstring(L"An empty line has been entered");

	filesWorker->Create(CurrentDirectory::Path, name);
}