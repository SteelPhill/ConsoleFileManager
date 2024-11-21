#include "ShowContentsCurrentDirectoryCommand.h"

ShowContentsCurrentDirectoryCommand::ShowContentsCurrentDirectoryCommand(std::wstring description)
{
	this->description = description;
	contentWriter = new DirectoryContentConsoleWriter();
}

ShowContentsCurrentDirectoryCommand::~ShowContentsCurrentDirectoryCommand()
{
	delete contentWriter;
}

std::wstring ShowContentsCurrentDirectoryCommand::GetDescription() const
{
	return description;
}

void ShowContentsCurrentDirectoryCommand::Execute() const
{
	contentWriter->Write(CurrentDirectory::Path);
}