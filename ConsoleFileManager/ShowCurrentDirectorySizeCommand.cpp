#include "ShowCurrentDirectorySizeCommand.h"

ShowCurrentDirectorySizeCommand::ShowCurrentDirectorySizeCommand()
{
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
}

ShowCurrentDirectorySizeCommand::~ShowCurrentDirectorySizeCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
}

std::wstring ShowCurrentDirectorySizeCommand::GetDescription() const
{
	return L"Show current directory size";
}

void ShowCurrentDirectorySizeCommand::Execute() const
{
	system("cls");

	std::wcout << "Size of directory: ";
	coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);

	std::wcout << std::endl << std::endl << "\t";
	coloredTextWriter->Write(directoriesWorker->GetSizeInBytes(CurrentDirectory::Path), Constants::BlackOnWhiteTextCode);
	std::wcout << " bytes" << std::endl << std::endl;

	system("pause");
}