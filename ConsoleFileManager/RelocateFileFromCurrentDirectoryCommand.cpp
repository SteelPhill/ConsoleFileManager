#include "RelocateFileFromCurrentDirectoryCommand.h"

RelocateFileFromCurrentDirectoryCommand::RelocateFileFromCurrentDirectoryCommand(std::wstring description, std::wstring title)
{
	this->description = description;
	this->title = title;
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	filesWorker = new FilesWorker();
	menuSelector = new ConsoleMenuSelector();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RelocateFileFromCurrentDirectoryCommand::~RelocateFileFromCurrentDirectoryCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete filesWorker;
	delete menuSelector;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RelocateFileFromCurrentDirectoryCommand::GetDescription() const
{
	return description;
}

void RelocateFileFromCurrentDirectoryCommand::Execute() const
{
	std::wstring fileToRelocate = menuSelector->Select(title, directoriesWorker->GetFiles(CurrentDirectory::Path));

	if (fileToRelocate.empty())
		return;

	fileToRelocate.replace(0, Constants::ExplanatoryLineSize, L"");

	system("cls");

	std::wcout << "Current directory:" << std::endl;
	coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);
	std::wcout << std::endl << std::endl;

	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	filesWorker->Relocate(fileToRelocate, destinationDirectory);
}