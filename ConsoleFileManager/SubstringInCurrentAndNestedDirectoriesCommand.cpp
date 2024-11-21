#include "SubstringInCurrentAndNestedDirectoriesCommand.h"

SubstringInCurrentAndNestedDirectoriesCommand::SubstringInCurrentAndNestedDirectoriesCommand(std::wstring description)
{
	this->description = description;
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

SubstringInCurrentAndNestedDirectoriesCommand::~SubstringInCurrentAndNestedDirectoriesCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring SubstringInCurrentAndNestedDirectoriesCommand::GetDescription() const
{
	return description;
}

void SubstringInCurrentAndNestedDirectoriesCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter searched substring" << std::endl << std::endl;
	std::wstring searchedText = stringReader->Read();

	if (searchedText.empty() || spacesChecker->Check(searchedText))
		throw std::wstring(L"An empty line has been entered");

	system("cls");

	std::wcout << "Search result for substring \"";
	coloredTextWriter->Write(searchedText, Constants::BlackOnWhiteTextCode);
	std::wcout << "\" in current and nested directories:" << std::endl;
	coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);
	std::wcout << std::endl << std::endl;

	std::wstring result = directoriesWorker->SubstringSearch(CurrentDirectory::Path, searchedText, false);

	if (result.empty())
		std::wcout << "\tSearch did not yield any results" << std::endl << std::endl;
	else
		std::wcout << result << std::endl;

	system("pause");
}