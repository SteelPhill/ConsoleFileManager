#include <iostream>
#include <filesystem>
#include <io.h>
#include <fcntl.h>
#include "IMenu.h"
#include "ConsoleMenu.h"
#include "CurrentDirectory.h"
#include "ChangeCurrentDirectoryCommand.h"
#include "ChangeCurrentDirectoryToEnteredCommand.h"
#include "ChangeCurrentDirectoryToPreviousCommand.h"
#include "ChangeCurrentDirectoryToSelectedCommand.h"
#include "ShowDirectoryContentCommand.h"
#include "ShowCurrentDirectorySizeCommand.h"
#include "ShowEnteredDirectorySizeCommand.h"
#include "ShowSelectedDirectorySizeCommand.h"
#include "WorkingWithDirectoriesCommand.h"
#include "ShowDirectorySizeCommand.h"
#include "ShowContentsCurrentDirectoryCommand.h"
#include "ShowContentsEnteredDirectoryCommand.h"
#include "CreateDirectoryCommand.h"
#include "CreateDirectoryInCurrentDirectoryCommand.h"
#include "CreateDirectoryInEnteredDirectoryCommand.h"
#include "CopyDirectoryCommand.h"
#include "CopyDirectoryFromCurrentDirectoryCommand.h"
#include "CopyEnteredDirectoryCommand.h"
#include "RelocateDirectoryCommand.h"
#include "RelocateDirectoryFromCurrentDirectoryCommand.h"
#include "RelocateEnteredDirectoryCommand.h"
#include "RenameDirectoryCommand.h"
#include "RenameDirectoryFromCurrentDirectoryCommand.h"
#include "RenameEnteredDirectoryCommand.h"
#include "RemoveDirectoryCommand.h"
#include "RemoveDirectoryFromCurrentDirectoryCommand.h"
#include "RemoveEnteredDirectoryCommand.h"
#include "WorkingWithFilesCommand.h"
#include "ShowFileSizeCommand.h"
#include "ShowEnteredFileSizeCommand.h"
#include "ShowSelectedFileSizeCommand.h"
#include "CreateFileCommand.h"
#include "CreateFileInCurrentDirectoryCommand.h"
#include "CreateFileInEnteredDirectoryCommand.h"
#include "CopyFileCommand.h"
#include "CopyEnteredFileCommand.h"
#include "CopyFileFromCurrentDirectoryCommand.h"
#include "RelocateFileCommand.h"
#include "RelocateEnteredFileCommand.h"
#include "RelocateFileFromCurrentDirectoryCommand.h"
#include "RenameFileCommand.h"
#include "RenameEnteredFileCommand.h"
#include "RenameFileFromCurrentDirectoryCommand.h"
#include "RemoveFileCommand.h"
#include "RemoveEnteredFileCommand.h"
#include "RemoveFileFromCurrentDirectoryCommand.h"
#include "SearchSubstringCommand.h"
#include "SubstringInCurrentAndNestedDirectoriesCommand.h"
#include "SubstringInEnteredAndNestedDirectoriesCommand.h"
#include "SubstringInOnlyCurrentDirectoryCommand.h"
#include "SubstringInOnlyEnteredDirectoryCommand.h"
using namespace std;
using namespace std::filesystem;

static void CreateMenuAndStartFileManager()
{
	CurrentDirectory::Path = current_path().wstring();

	IMenu* showDirectoryContentMenu = new ConsoleMenu(L"Show directory content options:");
	showDirectoryContentMenu->AddCommand(new ShowContentsCurrentDirectoryCommand());
	showDirectoryContentMenu->AddCommand(new ShowContentsEnteredDirectoryCommand());

	IMenu* changeCurrentDirectoryMenu = new ConsoleMenu(L"Change current directory options");
	changeCurrentDirectoryMenu->AddCommand(new ChangeCurrentDirectoryToPreviousCommand());
	changeCurrentDirectoryMenu->AddCommand(new ChangeCurrentDirectoryToSelectedCommand());
	changeCurrentDirectoryMenu->AddCommand(new ChangeCurrentDirectoryToEnteredCommand());

	IMenu* showDirectorySizeMenu = new ConsoleMenu(L"Show directory size options:");
	showDirectorySizeMenu->AddCommand(new ShowCurrentDirectorySizeCommand());
	showDirectorySizeMenu->AddCommand(new ShowSelectedDirectorySizeCommand());
	showDirectorySizeMenu->AddCommand(new ShowEnteredDirectorySizeCommand());

	IMenu* createDirectoryMenu = new ConsoleMenu(L"Create directory options:");
	createDirectoryMenu->AddCommand(new CreateDirectoryInCurrentDirectoryCommand());
	createDirectoryMenu->AddCommand(new CreateDirectoryInEnteredDirectoryCommand());

	IMenu* copyDirectoryMenu = new ConsoleMenu(L"Copy directory options:");
	copyDirectoryMenu->AddCommand(new CopyDirectoryFromCurrentDirectoryCommand());
	copyDirectoryMenu->AddCommand(new CopyEnteredDirectoryCommand());

	IMenu* relocateDirectoryMenu = new ConsoleMenu(L"Relocate directory options:");
	relocateDirectoryMenu->AddCommand(new RelocateDirectoryFromCurrentDirectoryCommand());
	relocateDirectoryMenu->AddCommand(new RelocateEnteredDirectoryCommand());

	IMenu* renameDirectoryMenu = new ConsoleMenu(L"Rename directory options:");
	renameDirectoryMenu->AddCommand(new RenameDirectoryFromCurrentDirectoryCommand());
	renameDirectoryMenu->AddCommand(new RenameEnteredDirectoryCommand());

	IMenu* removeDirectoryMenu = new ConsoleMenu(L"Remove directory options:");
	removeDirectoryMenu->AddCommand(new RemoveDirectoryFromCurrentDirectoryCommand());
	removeDirectoryMenu->AddCommand(new RemoveEnteredDirectoryCommand());

	IMenu* workingWithDirectoriesMenu = new ConsoleMenu(L"Working with directories options:");
	workingWithDirectoriesMenu->AddCommand(new ShowDirectorySizeCommand(showDirectorySizeMenu));
	workingWithDirectoriesMenu->AddCommand(new CreateDirectoryCommand(createDirectoryMenu));
	workingWithDirectoriesMenu->AddCommand(new CopyDirectoryCommand(copyDirectoryMenu));
	workingWithDirectoriesMenu->AddCommand(new RelocateDirectoryCommand(relocateDirectoryMenu));
	workingWithDirectoriesMenu->AddCommand(new RenameDirectoryCommand(renameDirectoryMenu));
	workingWithDirectoriesMenu->AddCommand(new RemoveDirectoryCommand(removeDirectoryMenu));

	IMenu* showFileSizeMenu = new ConsoleMenu(L"Show file size options:");
	showFileSizeMenu->AddCommand(new ShowSelectedFileSizeCommand());
	showFileSizeMenu->AddCommand(new ShowEnteredFileSizeCommand());

	IMenu* createFileMenu = new ConsoleMenu(L"Create file options:");
	createFileMenu->AddCommand(new CreateFileInCurrentDirectoryCommand());
	createFileMenu->AddCommand(new CreateFileInEnteredDirectoryCommand());

	IMenu* copyFileMenu = new ConsoleMenu(L"Copy file options:");
	copyFileMenu->AddCommand(new CopyFileFromCurrentDirectoryCommand());
	copyFileMenu->AddCommand(new CopyEnteredFileCommand());

	IMenu* relocateFileMenu = new ConsoleMenu(L"Relocate file options:");
	relocateFileMenu->AddCommand(new RelocateFileFromCurrentDirectoryCommand());
	relocateFileMenu->AddCommand(new RelocateEnteredFileCommand());

	IMenu* renameFileMenu = new ConsoleMenu(L"Rename file options:");
	renameFileMenu->AddCommand(new RenameFileFromCurrentDirectoryCommand());
	renameFileMenu->AddCommand(new RenameEnteredFileCommand());

	IMenu* removeFileMenu = new ConsoleMenu(L"Remove file options:");
	removeFileMenu->AddCommand(new RemoveFileFromCurrentDirectoryCommand());
	removeFileMenu->AddCommand(new RemoveEnteredFileCommand());

	IMenu* workingWithFilesMenu = new ConsoleMenu(L"Working with files options:");
	workingWithFilesMenu->AddCommand(new ShowFileSizeCommand(showFileSizeMenu));
	workingWithFilesMenu->AddCommand(new CreateFileCommand(createFileMenu));
	workingWithFilesMenu->AddCommand(new CopyFileCommand(copyFileMenu));
	workingWithFilesMenu->AddCommand(new RelocateFileCommand(relocateFileMenu));
	workingWithFilesMenu->AddCommand(new RenameFileCommand(renameFileMenu));
	workingWithFilesMenu->AddCommand(new RemoveFileCommand(removeFileMenu));

	IMenu* searchSubstringMenu = new ConsoleMenu(L"Search substring options:");
	searchSubstringMenu->AddCommand(new SubstringInOnlyCurrentDirectoryCommand());
	searchSubstringMenu->AddCommand(new SubstringInCurrentAndNestedDirectoriesCommand());
	searchSubstringMenu->AddCommand(new SubstringInOnlyEnteredDirectoryCommand());
	searchSubstringMenu->AddCommand(new SubstringInEnteredAndNestedDirectoriesCommand());

	IMenu* mainMenu = new ConsoleMenu(L"File manager main menu:");
	mainMenu->AddCommand(new ShowDirectoryContentCommand(showDirectoryContentMenu));
	mainMenu->AddCommand(new ChangeCurrentDirectoryCommand(changeCurrentDirectoryMenu));
	mainMenu->AddCommand(new WorkingWithDirectoriesCommand(workingWithDirectoriesMenu));
	mainMenu->AddCommand(new WorkingWithFilesCommand(workingWithFilesMenu));
	mainMenu->AddCommand(new SearchSubstringCommand(searchSubstringMenu));

	mainMenu->Start();

	delete showDirectoryContentMenu;
	delete changeCurrentDirectoryMenu;
	delete showDirectorySizeMenu;
	delete createDirectoryMenu;
	delete copyDirectoryMenu;
	delete relocateDirectoryMenu;
	delete renameDirectoryMenu;
	delete removeDirectoryMenu;
	delete workingWithDirectoriesMenu;
	delete showFileSizeMenu;
	delete createFileMenu;
	delete copyFileMenu;
	delete relocateFileMenu;
	delete renameFileMenu;
	delete removeFileMenu;
	delete workingWithFilesMenu;
	delete searchSubstringMenu;
	delete mainMenu;
}

void main()
{
	(void)_setmode(_fileno(stdout), _O_U16TEXT);
	(void)_setmode(_fileno(stdin), _O_U16TEXT);

	CreateMenuAndStartFileManager();
}