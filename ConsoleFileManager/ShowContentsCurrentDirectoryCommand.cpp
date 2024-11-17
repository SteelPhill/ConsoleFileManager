#include "ShowContentsCurrentDirectoryCommand.h"

ShowContentsCurrentDirectoryCommand::ShowContentsCurrentDirectoryCommand()
{
	contentWriter = new DirectoryContentConsoleWriter();
}

ShowContentsCurrentDirectoryCommand::~ShowContentsCurrentDirectoryCommand()
{
	delete contentWriter;
}

std::wstring ShowContentsCurrentDirectoryCommand::GetDescription() const
{
	return L"Show contents of current directory";
}

void ShowContentsCurrentDirectoryCommand::Execute() const
{
	contentWriter->Write(CurrentDirectory::Path);
}