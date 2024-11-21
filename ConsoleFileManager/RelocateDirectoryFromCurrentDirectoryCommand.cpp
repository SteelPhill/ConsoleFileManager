#include "RelocateDirectoryFromCurrentDirectoryCommand.h"

RelocateDirectoryFromCurrentDirectoryCommand::RelocateDirectoryFromCurrentDirectoryCommand(std::wstring description, std::wstring title)
{
	this->description = description;
	this->title = title;
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	menuSelector = new ConsoleMenuSelector();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RelocateDirectoryFromCurrentDirectoryCommand::~RelocateDirectoryFromCurrentDirectoryCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete menuSelector;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RelocateDirectoryFromCurrentDirectoryCommand::GetDescription() const
{
	return description;
}

void RelocateDirectoryFromCurrentDirectoryCommand::Execute() const
{
	std::wstring directoryToRelocate = menuSelector->Select(title, directoriesWorker->GetDirectories(CurrentDirectory::Path));

	if (directoryToRelocate.empty())
		return;

	directoryToRelocate.replace(0, Constants::ExplanatoryLineSize, L"");

	system("cls");

	std::wcout << "Current directory:" << std::endl;
	coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);
	std::wcout << std::endl << std::endl;

	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	directoriesWorker->Relocate(directoryToRelocate, destinationDirectory);
}