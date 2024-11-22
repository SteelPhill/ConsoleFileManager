#include "RelocateEnteredFileCommand.h"

RelocateEnteredFileCommand::RelocateEnteredFileCommand(std::wstring description)
{
	this->description = description;
	filesWorker = new FilesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RelocateEnteredFileCommand::~RelocateEnteredFileCommand()
{
	delete filesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RelocateEnteredFileCommand::GetDescription() const
{
	return description;
}

void RelocateEnteredFileCommand::Execute() const
{
	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter file path to be relocated" << std::endl << std::endl;
	std::wstring fileToRelocate = stringReader->Read();

	if (fileToRelocate.empty() || spacesChecker->Check(fileToRelocate))
		throw std::wstring(L"An empty line has been entered");

	std::wcout << std::endl << "Enter path to destination directory" << std::endl << std::endl;
	std::wstring destinationDirectory = stringReader->Read();

	if (destinationDirectory.empty() || spacesChecker->Check(destinationDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (destinationDirectory.find(L"\\") == std::wstring::npos)
		destinationDirectory += L"\\";

	filesWorker->Relocate(fileToRelocate, destinationDirectory);
}