#include "RenameDirectoryFromCurrentDirectoryCommand.h"

RenameDirectoryFromCurrentDirectoryCommand::RenameDirectoryFromCurrentDirectoryCommand(std::wstring description, std::wstring title)
{
	this->description = description;
	this->title = title;
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	menuSelector = new ConsoleMenuSelector();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RenameDirectoryFromCurrentDirectoryCommand::~RenameDirectoryFromCurrentDirectoryCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete menuSelector;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RenameDirectoryFromCurrentDirectoryCommand::GetDescription() const
{
	return description;
}

void RenameDirectoryFromCurrentDirectoryCommand::Execute() const
{
	std::wstring directoryToRename = menuSelector->Select(title, directoriesWorker->GetDirectories(CurrentDirectory::Path));

	if (directoryToRename.empty())
		return;

	directoryToRename.replace(0, Constants::ExplanatoryLineSize, L"");

	system("cls");

	std::wcout << "Current directory:" << std::endl;
	coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);
	std::wcout << std::endl << std::endl;

	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter new name" << std::endl << std::endl;
	std::wstring newName = stringReader->Read();

	if (newName.empty() || spacesChecker->Check(newName))
		throw std::wstring(L"An empty line has been entered");

	directoriesWorker->Rename(directoryToRename, newName);
}