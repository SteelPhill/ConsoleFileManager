#include "ShowEnteredDirectorySizeCommand.h"

ShowEnteredDirectorySizeCommand::ShowEnteredDirectorySizeCommand(std::wstring description)
{
	this->description = description;
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	stringReader = new ConsoleStringReader();
	spacesChecker = new StringSpacesChecker();
}

ShowEnteredDirectorySizeCommand::~ShowEnteredDirectorySizeCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete stringReader;
	delete spacesChecker;
}

std::wstring ShowEnteredDirectorySizeCommand::GetDescription() const
{
	return description;
}

void ShowEnteredDirectorySizeCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter directory path to display its size" << std::endl << std::endl;
	std::wstring enteredDirectory = stringReader->Read();

	if (enteredDirectory.empty() || spacesChecker->Check(enteredDirectory))
		throw std::wstring(L"An empty line has been entered");

	if (enteredDirectory.find(L"\\") == std::wstring::npos)
		enteredDirectory += L"\\";

	system("cls");

	std::wcout << "Size of directory: ";
	coloredTextWriter->Write(enteredDirectory, Constants::BlackOnWhiteTextCode);

	std::wcout << std::endl << std::endl << "\t";
	coloredTextWriter->Write(directoriesWorker->GetSizeInBytes(enteredDirectory), Constants::BlackOnWhiteTextCode);
	std::wcout << " bytes" << std::endl << std::endl;

	system("pause");
}