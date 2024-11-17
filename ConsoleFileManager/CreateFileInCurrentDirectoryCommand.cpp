#include "CreateFileInCurrentDirectoryCommand.h"

CreateFileInCurrentDirectoryCommand::CreateFileInCurrentDirectoryCommand()
{
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
	return L"Create file in current directory";
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