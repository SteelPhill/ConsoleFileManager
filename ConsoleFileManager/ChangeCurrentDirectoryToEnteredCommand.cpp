#include "ChangeCurrentDirectoryToEnteredCommand.h"

ChangeCurrentDirectoryToEnteredCommand::ChangeCurrentDirectoryToEnteredCommand()
{
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

ChangeCurrentDirectoryToEnteredCommand::~ChangeCurrentDirectoryToEnteredCommand()
{
	delete stringReader;
	delete spacesChecker;
}

std::wstring ChangeCurrentDirectoryToEnteredCommand::GetDescription() const
{
	return L"Change current directory to entered";
}

void ChangeCurrentDirectoryToEnteredCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter new current directory path" << std::endl << std::endl;
	std::wstring newCurrentDirectory = stringReader->Read();

	if (newCurrentDirectory.empty() || spacesChecker->Check(newCurrentDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (newCurrentDirectory.find(L"\\") == std::wstring::npos)
		newCurrentDirectory += L"\\";

	if (!fs::is_directory(newCurrentDirectory))
		throw std::wstring(L"Directory does not exist");

	CurrentDirectory::Path = newCurrentDirectory;
}