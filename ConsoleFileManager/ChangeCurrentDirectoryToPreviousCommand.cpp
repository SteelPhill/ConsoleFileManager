#include "ChangeCurrentDirectoryToPreviousCommand.h"

ChangeCurrentDirectoryToPreviousCommand::ChangeCurrentDirectoryToPreviousCommand(std::wstring description)
{
	this->description = description;
}

std::wstring ChangeCurrentDirectoryToPreviousCommand::GetDescription() const
{
	return description;
}

void ChangeCurrentDirectoryToPreviousCommand::Execute() const
{
	CurrentDirectory::Path = CurrentDirectory::Path.substr(0, CurrentDirectory::Path.rfind(L"\\"));

	if (CurrentDirectory::Path.find(L"\\") == std::wstring::npos)
		CurrentDirectory::Path += L"\\";
}