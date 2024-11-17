#include "DirectoryContentConsoleWriter.h"

DirectoryContentConsoleWriter::DirectoryContentConsoleWriter()
{
	coloredTextWriter = new ColoredTextConsoleWriter();
	directoriesWorker = new DirectoriesWorker();
}

DirectoryContentConsoleWriter::~DirectoryContentConsoleWriter()
{
	delete coloredTextWriter;
	delete directoriesWorker;
}

void DirectoryContentConsoleWriter::Write(const std::wstring& directory) const
{
	system("cls");
	std::wcout << "Content of ";
	coloredTextWriter->Write(directory, Constants::BlackOnWhiteTextCode);
	std::wcout << ":" << std::endl << std::endl;

	std::vector<std::wstring> items = directoriesWorker->GetAllItems(directory);

	if (items.empty())
	{
		std::wcout << "\t";
		coloredTextWriter->Write(L"Directory is empty", Constants::BlackOnWhiteTextCode);
		std::wcout << std::endl;
	}
	else
	{
		for (const auto& item : items)
			std::wcout << item << std::endl;
	}

	std::wcout << std::endl;
	system("pause");
}