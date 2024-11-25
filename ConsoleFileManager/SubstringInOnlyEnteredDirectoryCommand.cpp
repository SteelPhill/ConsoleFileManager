#include "SubstringInOnlyEnteredDirectoryCommand.h"

SubstringInOnlyEnteredDirectoryCommand::SubstringInOnlyEnteredDirectoryCommand(std::wstring description)
{
	this->description = description;
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

SubstringInOnlyEnteredDirectoryCommand::~SubstringInOnlyEnteredDirectoryCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring SubstringInOnlyEnteredDirectoryCommand::GetDescription() const
{
	return description;
}

void SubstringInOnlyEnteredDirectoryCommand::Execute() const
{
	std::wcout << "\t" << description << ":" << std::endl << std::endl;

	std::wcout << "Enter path to directory to search for substring" << std::endl << std::endl;
	std::wstring directoryToSearch = stringReader->Read();

	if (directoryToSearch.empty() || spacesChecker->Check(directoryToSearch))
		throw std::wstring(L"An empty line has been entered");

	if (directoryToSearch.find(L"\\") == std::wstring::npos)
		directoryToSearch += L"\\";

	std::wcout << std::endl << "Enter searched substring" << std::endl << std::endl;
	std::wstring searchedText = stringReader->Read();

	if (searchedText.empty() || spacesChecker->Check(searchedText))
		throw std::wstring(L"An empty line has been entered");

	system("cls");

	std::wcout << "Search result for substring \"";
	coloredTextWriter->Write(searchedText, Constants::BlackOnWhiteTextCode);
	std::wcout << "\" only in entered directory:" << std::endl;
	coloredTextWriter->Write(directoryToSearch, Constants::BlackOnWhiteTextCode);
	std::wcout << std::endl << std::endl;

	std::wstring result = directoriesWorker->SubstringSearch(directoryToSearch, searchedText, true);

	if (result.empty())
		std::wcout << "\tSearch did not yield any results" << std::endl << std::endl;
	else
		std::wcout << result << std::endl;

	system("pause");
}