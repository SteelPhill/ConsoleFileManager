#include "ShowSelectedDirectorySizeCommand.h"

ShowSelectedDirectorySizeCommand::ShowSelectedDirectorySizeCommand()
{
	title = L"\tSelect directory to display its size:";
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	menuSelector = new ConsoleMenuSelector();
}

ShowSelectedDirectorySizeCommand::~ShowSelectedDirectorySizeCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete menuSelector;
}

std::wstring ShowSelectedDirectorySizeCommand::GetDescription() const
{
	return L"Show selected directory size";
}

void ShowSelectedDirectorySizeCommand::Execute() const
{
	std::wstring selectedDirectory = menuSelector->Select(title, directoriesWorker->GetDirectories(CurrentDirectory::Path));

	if (selectedDirectory.empty())
		return;

	selectedDirectory.replace(0, Constants::ExplanatoryLineSize, L"");

	system("cls");

	std::wcout << "Size of directory: ";
	coloredTextWriter->Write(selectedDirectory, Constants::BlackOnWhiteTextCode);

	std::wcout << std::endl << std::endl << "\t";
	coloredTextWriter->Write(directoriesWorker->GetSizeInBytes(selectedDirectory), Constants::BlackOnWhiteTextCode);
	std::wcout << " bytes" << std::endl << std::endl;

	system("pause");
}