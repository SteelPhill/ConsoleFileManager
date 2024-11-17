#include <iostream>
#include <filesystem>
#include <io.h>
#include <fcntl.h>
#include "ChangeCurrentDirectoryCommand.h"
#include "ConsoleMenu.h"
#include "CurrentDirectory.h"
#include "SearchSubstringCommand.h"
#include "ShowDirectoryContentCommand.h"
#include "WorkingWithDirectoriesCommand.h"
#include "WorkingWithFilesCommand.h"
using namespace std;
using namespace std::filesystem;

void FileManagerStart()
{
	const wstring Title = L"File manager main menu:";

	CurrentDirectory::Path = current_path().wstring();

	IMenu* mainMenu = new ConsoleMenu(Title);

	mainMenu->AddCommand(new ShowDirectoryContentCommand());
	mainMenu->AddCommand(new ChangeCurrentDirectoryCommand());
	mainMenu->AddCommand(new WorkingWithDirectoriesCommand());
	mainMenu->AddCommand(new WorkingWithFilesCommand());
	mainMenu->AddCommand(new SearchSubstringCommand());

	mainMenu->Start();

	delete mainMenu;
}

void main()
{
	(void)_setmode(_fileno(stdout), _O_U16TEXT);
	(void)_setmode(_fileno(stdin), _O_U16TEXT);

	FileManagerStart();
}