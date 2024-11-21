#include "CopyEnteredFileCommand.h"

CopyEnteredFileCommand::CopyEnteredFileCommand(std::wstring description)
{
	this->description = description;
	filesWorker = new FilesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

CopyEnteredFileCommand::~CopyEnteredFileCommand()
{
	delete filesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring CopyEnteredFileCommand::GetDescription() const
{
	return description;
}

void CopyEnteredFileCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter file path to be copied" << std::endl << std::endl;
	std::wstring fileToCopy = stringReader->Read();

	if (fileToCopy.empty() || spacesChecker->Check(fileToCopy))
		throw std::wstring(L"An empty line has been entered");

	std::wcout << std::endl << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	filesWorker->Copy(fileToCopy, destinationDirectory);
}