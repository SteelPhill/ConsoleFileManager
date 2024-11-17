#include "RenameEnteredDirectoryCommand.h"

RenameEnteredDirectoryCommand::RenameEnteredDirectoryCommand()
{
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RenameEnteredDirectoryCommand::~RenameEnteredDirectoryCommand()
{
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RenameEnteredDirectoryCommand::GetDescription() const
{
	return L"Rename entered directory";
}

void RenameEnteredDirectoryCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter directory path to be renamed" << std::endl << std::endl;
	std::wstring directoryToRename = stringReader->Read();

	if (directoryToRename.empty() || spacesChecker->Check(directoryToRename))
		throw std::wstring(L"An empty line has been entered");

	if (directoryToRename.find(L"\\") == std::wstring::npos)
		directoryToRename += L"\\";

	std::wcout << std::endl << "Enter new name" << std::endl << std::endl;
	std::wstring newName = stringReader->Read();

	if (newName.empty() || spacesChecker->Check(newName))
		throw std::wstring(L"An empty line has been entered");

	directoriesWorker->Rename(directoryToRename, newName);
}