#include "ChangeCurrentDirectoryToPreviousCommand.h"

std::wstring ChangeCurrentDirectoryToPreviousCommand::GetDescription() const
{
	return L"Change current directory to previous";
}

void ChangeCurrentDirectoryToPreviousCommand::Execute() const
{
	CurrentDirectory::Path = CurrentDirectory::Path.substr(0, CurrentDirectory::Path.rfind(L"\\"));

	if (CurrentDirectory::Path.find(L"\\") == std::wstring::npos)
		CurrentDirectory::Path += L"\\";
}