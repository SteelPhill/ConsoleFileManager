#include "RenameEnteredFileCommand.h"

RenameEnteredFileCommand::RenameEnteredFileCommand(std::wstring description)
{
	this->description = description;
	filesWorker = new FilesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RenameEnteredFileCommand::~RenameEnteredFileCommand()
{
	delete filesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RenameEnteredFileCommand::GetDescription() const
{
	return description;
}

void RenameEnteredFileCommand::Execute() const
{
	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter file path to be renamed" << std::endl << std::endl;
	std::wstring fileToRename = stringReader->Read();

	if (fileToRename.empty() || spacesChecker->Check(fileToRename))
		throw std::wstring(L"An empty line has been entered");

	std::wcout << std::endl << "Enter new name" << std::endl << std::endl;
	std::wstring newName = stringReader->Read();

	if (newName.empty() || spacesChecker->Check(newName))
		throw std::wstring(L"An empty line has been entered");

	filesWorker->Rename(fileToRename, newName);
}