#include "RenameFileFromCurrentDirectoryCommand.h"

RenameFileFromCurrentDirectoryCommand::RenameFileFromCurrentDirectoryCommand(std::wstring description, std::wstring title)
{
	this->description = description;
	this->title = title;
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	filesWorker = new FilesWorker();
	menuSelector = new ConsoleMenuSelector();
	stringReader = new ConsoleStringReader();
	spaceChecker = new StringSpacesChecker();
}

RenameFileFromCurrentDirectoryCommand::~RenameFileFromCurrentDirectoryCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete filesWorker;
	delete menuSelector;
	delete stringReader;
	delete spaceChecker;
}

std::wstring RenameFileFromCurrentDirectoryCommand::GetDescription() const
{
	return description;
}

void RenameFileFromCurrentDirectoryCommand::Execute() const
{
	std::wstring fileToRename = menuSelector->Select(title, directoriesWorker->GetFiles(CurrentDirectory::Path));

	if (fileToRename.empty())
		return;

	fileToRename.replace(0, Constants::ExplanatoryLineSize, L"");

	system("cls");

	std::wcout << "Current directory:" << std::endl;
	coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);
	std::wcout << std::endl << std::endl;

	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter new name" << std::endl << std::endl;
	std::wstring newName = stringReader->Read();

	if (newName.empty() || spaceChecker->Check(newName))
		throw std::wstring(L"An empty line has been entered");

	filesWorker->Rename(fileToRename, newName);
}