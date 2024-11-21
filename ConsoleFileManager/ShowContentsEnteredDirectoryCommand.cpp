#include "ShowContentsEnteredDirectoryCommand.h"

ShowContentsEnteredDirectoryCommand::ShowContentsEnteredDirectoryCommand(std::wstring description)
{
	this->description = description;
	contentWriter = new DirectoryContentConsoleWriter();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

ShowContentsEnteredDirectoryCommand::~ShowContentsEnteredDirectoryCommand()
{
	delete contentWriter;
	delete stringReader;
	delete spacesChecker;
}

std::wstring ShowContentsEnteredDirectoryCommand::GetDescription() const
{
	return description;
}

void ShowContentsEnteredDirectoryCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter path to directory to display its contents" << std::endl << std::endl;
	std::wstring enteredDirectory = stringReader->Read();

	if (enteredDirectory.empty() || spacesChecker->Check(enteredDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (enteredDirectory.find(L"\\") == std::wstring::npos)
		enteredDirectory += L"\\";

	contentWriter->Write(enteredDirectory);
}