#include "ShowSelectedDirectorySizeCommand.h"

ShowSelectedDirectorySizeCommand::ShowSelectedDirectorySizeCommand(std::wstring description, std::wstring title)
{
	this->description = description;
	this->title = title;
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
	return description;
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