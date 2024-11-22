#include "CopyFileFromCurrentDirectoryCommand.h"

CopyFileFromCurrentDirectoryCommand::CopyFileFromCurrentDirectoryCommand(std::wstring description, std::wstring title)
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

CopyFileFromCurrentDirectoryCommand::~CopyFileFromCurrentDirectoryCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete filesWorker;
	delete menuSelector;
	delete stringReader;
	delete spacesChecker;
}

std::wstring CopyFileFromCurrentDirectoryCommand::GetDescription() const
{
	return description;
}

void CopyFileFromCurrentDirectoryCommand::Execute() const
{
	std::wstring fileToCopy = menuSelector->Select(title, directoriesWorker->GetFiles(CurrentDirectory::Path));

	if (fileToCopy.empty())
		return;

	fileToCopy.replace(0, Constants::ExplanatoryLineSize, L"");

	system("cls");

	std::wcout << "Current location:" << std::endl;
	coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);
	std::wcout << std::endl << std::endl;

	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	filesWorker->Copy(fileToCopy, destinationDirectory);
}