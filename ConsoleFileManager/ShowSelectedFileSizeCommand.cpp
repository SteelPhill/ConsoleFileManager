#include "ShowSelectedFileSizeCommand.h"

ShowSelectedFileSizeCommand::ShowSelectedFileSizeCommand()
{
	title = L"\tSelect file to display its size:";
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
	filesWorker = new FilesWorker();
	menuSelector = new ConsoleMenuSelector();
}

ShowSelectedFileSizeCommand::~ShowSelectedFileSizeCommand()
{
	delete coloredTextWriter;
	delete directoriesWorker;
	delete filesWorker;
	delete menuSelector;
}

std::wstring ShowSelectedFileSizeCommand::GetDescription() const
{
	return L"Show selected file size";
}

void ShowSelectedFileSizeCommand::Execute() const
{
	std::wstring selectedFile = menuSelector->Select(title, directoriesWorker->GetFiles(CurrentDirectory::Path));

	if (selectedFile.empty())
		return;

	selectedFile.replace(0, Constants::ExplanatoryLineSize, L"");

	system("cls");

	std::wcout << "Size of file: ";
	coloredTextWriter->Write(selectedFile, Constants::BlackOnWhiteTextCode);

	std::wcout << std::endl << std::endl << "\t";
	coloredTextWriter->Write(filesWorker->GetSizeInBytes(selectedFile), Constants::BlackOnWhiteTextCode);
	std::wcout << " bytes" << std::endl << std::endl;

	system("pause");
}