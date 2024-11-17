#include "ShowEnteredFileSizeCommand.h"

ShowEnteredFileSizeCommand::ShowEnteredFileSizeCommand()
{
	coloredTextWriter = new ColoredTextConsoleWriter();
	filesWorker = new FilesWorker();
	stringReader = new ConsoleStringReader();
	spaceChecker = new StringSpacesChecker();
}

ShowEnteredFileSizeCommand::~ShowEnteredFileSizeCommand()
{
	delete coloredTextWriter;
	delete filesWorker;
	delete stringReader;
	delete spaceChecker;
}

std::wstring ShowEnteredFileSizeCommand::GetDescription() const
{
	return L"Show entered file size";
}

void ShowEnteredFileSizeCommand::Execute() const
{
	std::wcout << "\t" << GetDescription() << ":" << std::endl << std::endl;

	std::wcout << "Enter file path to display its size" << std::endl << std::endl;
	std::wstring enteredFile = stringReader->Read();

	if (enteredFile.empty() || spaceChecker->Check(enteredFile))
		throw std::wstring(L"An empty line has been entered");

	system("cls");

	std::wcout << "Size of file: ";
	coloredTextWriter->Write(enteredFile, Constants::BlackOnWhiteTextCode);

	std::wcout << std::endl << std::endl << "\t";
	coloredTextWriter->Write(filesWorker->GetSizeInBytes(enteredFile), Constants::BlackOnWhiteTextCode);
	std::wcout << " bytes" << std::endl << std::endl;

	system("pause");
}