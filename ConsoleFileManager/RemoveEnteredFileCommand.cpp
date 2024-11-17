#include "RemoveEnteredFileCommand.h"

RemoveEnteredFileCommand::RemoveEnteredFileCommand()
{
	filesWorker = new FilesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

RemoveEnteredFileCommand::~RemoveEnteredFileCommand()
{
	delete filesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring RemoveEnteredFileCommand::GetDescription() const
{
	return L"Remove entered file";
}

void RemoveEnteredFileCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter file path to be removed" << std::endl << std::endl;
	std::wstring fileToRemove = stringReader->Read();

	if (fileToRemove.empty() || spacesChecker->Check(fileToRemove))
		throw std::wstring(L"An empty line has been entered");

	filesWorker->Remove(fileToRemove);
}