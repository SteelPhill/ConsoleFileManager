#include <iostream>
#include <filesystem>
#include <io.h>
#include <fcntl.h>
#include "IMenu.h"
#include "ConsoleMenu.h"
#include "SubmenuExecuterCommand.h"
#include "CurrentDirectory.h"
#include "ShowContentsCurrentDirectoryCommand.h"
#include "ShowContentsEnteredDirectoryCommand.h"
#include "ChangeCurrentDirectoryToEnteredCommand.h"
#include "ChangeCurrentDirectoryToPreviousCommand.h"
#include "ChangeCurrentDirectoryToSelectedCommand.h"
#include "ShowCurrentDirectorySizeCommand.h"
#include "ShowEnteredDirectorySizeCommand.h"
#include "ShowSelectedDirectorySizeCommand.h"
#include "CreateDirectoryInCurrentDirectoryCommand.h"
#include "CreateDirectoryInEnteredDirectoryCommand.h"
#include "CopyDirectoryFromCurrentDirectoryCommand.h"
#include "CopyEnteredDirectoryCommand.h"
#include "RelocateDirectoryFromCurrentDirectoryCommand.h"
#include "RelocateEnteredDirectoryCommand.h"
#include "RenameDirectoryFromCurrentDirectoryCommand.h"
#include "RenameEnteredDirectoryCommand.h"
#include "RemoveDirectoryFromCurrentDirectoryCommand.h"
#include "RemoveEnteredDirectoryCommand.h"
#include "ShowEnteredFileSizeCommand.h"
#include "ShowSelectedFileSizeCommand.h"
#include "CreateFileInCurrentDirectoryCommand.h"
#include "CreateFileInEnteredDirectoryCommand.h"
#include "CopyEnteredFileCommand.h"
#include "CopyFileFromCurrentDirectoryCommand.h"
#include "RelocateEnteredFileCommand.h"
#include "RelocateFileFromCurrentDirectoryCommand.h"
#include "RenameEnteredFileCommand.h"
#include "RenameFileFromCurrentDirectoryCommand.h"
#include "RemoveEnteredFileCommand.h"
#include "RemoveFileFromCurrentDirectoryCommand.h"
#include "SubstringInCurrentAndNestedDirectoriesCommand.h"
#include "SubstringInEnteredAndNestedDirectoriesCommand.h"
#include "SubstringInOnlyCurrentDirectoryCommand.h"
#include "SubstringInOnlyEnteredDirectoryCommand.h"
using namespace std;
using namespace std::filesystem;

static void CreateMenuAndStartFileManager()
{
	CurrentDirectory::Path = current_path().wstring();

	IMenu* showDirectoryContentSubmenu = new ConsoleMenu(L"Show directory content options:");
	showDirectoryContentSubmenu->AddCommand(new ShowContentsCurrentDirectoryCommand(L"Show contents of current directory"));
	showDirectoryContentSubmenu->AddCommand(new ShowContentsEnteredDirectoryCommand(L"Show contents of entered directory"));

	IMenu* changeCurrentDirectorySubmenu = new ConsoleMenu(L"Change current directory options");
	changeCurrentDirectorySubmenu->AddCommand(new ChangeCurrentDirectoryToPreviousCommand(L"Change current directory to previous"));
	changeCurrentDirectorySubmenu->AddCommand(new ChangeCurrentDirectoryToSelectedCommand(
		L"Change current directory to selected", L"\tSelect new current directory:"));
	changeCurrentDirectorySubmenu->AddCommand(new ChangeCurrentDirectoryToEnteredCommand(L"Change current directory to entered"));

	IMenu* showDirectorySizeSubmenu = new ConsoleMenu(L"Show directory size options:");
	showDirectorySizeSubmenu->AddCommand(new ShowCurrentDirectorySizeCommand(L"Show current directory size"));
	showDirectorySizeSubmenu->AddCommand(new ShowSelectedDirectorySizeCommand(
		L"Show selected directory size", L"\tSelect directory to display its size:"));
	showDirectorySizeSubmenu->AddCommand(new ShowEnteredDirectorySizeCommand(L"Show entered directory size"));

	IMenu* createDirectorySubmenu = new ConsoleMenu(L"Create directory options:");
	createDirectorySubmenu->AddCommand(new CreateDirectoryInCurrentDirectoryCommand(L"Create directory in current directory"));
	createDirectorySubmenu->AddCommand(new CreateDirectoryInEnteredDirectoryCommand(L"Create directory in entered directory"));

	IMenu* copyDirectorySubmenu = new ConsoleMenu(L"Copy directory options:");
	copyDirectorySubmenu->AddCommand(new CopyDirectoryFromCurrentDirectoryCommand(
		L"Copy directory from current directory", L"\tSelect directory path to be copied:"));
	copyDirectorySubmenu->AddCommand(new CopyEnteredDirectoryCommand(L"Copy entered directory"));

	IMenu* relocateDirectorySubmenu = new ConsoleMenu(L"Relocate directory options:");
	relocateDirectorySubmenu->AddCommand(new RelocateDirectoryFromCurrentDirectoryCommand(
		L"Relocate directory from current directory", L"\tSelect directory to be relocated:"));
	relocateDirectorySubmenu->AddCommand(new RelocateEnteredDirectoryCommand(L"Relocate entered directory"));

	IMenu* renameDirectorySubmenu = new ConsoleMenu(L"Rename directory options:");
	renameDirectorySubmenu->AddCommand(new RenameDirectoryFromCurrentDirectoryCommand(
		L"Rename directory from current directory", L"\tSelect directory to be renamed:"));
	renameDirectorySubmenu->AddCommand(new RenameEnteredDirectoryCommand(L"Rename entered directory"));

	IMenu* removeDirectorySubmenu = new ConsoleMenu(L"Remove directory options:");
	removeDirectorySubmenu->AddCommand(new RemoveDirectoryFromCurrentDirectoryCommand(
		L"Remove directory from current directory", L"\tSelect directory to be removed:"));
	removeDirectorySubmenu->AddCommand(new RemoveEnteredDirectoryCommand(L"Remove entered directory"));

	IMenu* workingWithDirectoriesSubmenu = new ConsoleMenu(L"Working with directories options:");
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Show directory size", showDirectorySizeSubmenu));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Create directory", createDirectorySubmenu));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Copy directory", copyDirectorySubmenu));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Relocate directory", relocateDirectorySubmenu));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Rename directory", renameDirectorySubmenu));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Remove directory", removeDirectorySubmenu));

	IMenu* showFileSizeSubmenu = new ConsoleMenu(L"Show file size options:");
	showFileSizeSubmenu->AddCommand(new ShowSelectedFileSizeCommand(
		L"Show selected file size", L"\tSelect file to display its size:"));
	showFileSizeSubmenu->AddCommand(new ShowEnteredFileSizeCommand(L"Show entered file size"));

	IMenu* createFileSubmenu = new ConsoleMenu(L"Create file options:");
	createFileSubmenu->AddCommand(new CreateFileInCurrentDirectoryCommand(L"Create file in current directory"));
	createFileSubmenu->AddCommand(new CreateFileInEnteredDirectoryCommand(L"Create file in entered directory"));

	IMenu* copyFileSubmenu = new ConsoleMenu(L"Copy file options:");
	copyFileSubmenu->AddCommand(new CopyFileFromCurrentDirectoryCommand(
		L"Copy file from current directory", L"\tSelect file to be copied:"));
	copyFileSubmenu->AddCommand(new CopyEnteredFileCommand(L"Copy entered file"));

	IMenu* relocateFileSubmenu = new ConsoleMenu(L"Relocate file options:");
	relocateFileSubmenu->AddCommand(new RelocateFileFromCurrentDirectoryCommand(
		L"Relocate file from current directory", L"\tSelect file to be relocated:"));
	relocateFileSubmenu->AddCommand(new RelocateEnteredFileCommand(L"Relocate entered file"));

	IMenu* renameFileSubmenu = new ConsoleMenu(L"Rename file options:");
	renameFileSubmenu->AddCommand(new RenameFileFromCurrentDirectoryCommand(
		L"Rename file from current directory", L"\tSelect file to be renamed:"));
	renameFileSubmenu->AddCommand(new RenameEnteredFileCommand(L"Rename entered file"));

	IMenu* removeFileSubmenu = new ConsoleMenu(L"Remove file options:");
	removeFileSubmenu->AddCommand(new RemoveFileFromCurrentDirectoryCommand(
		L"Remove file from current directory", L"\tSelect file to be removed:"));
	removeFileSubmenu->AddCommand(new RemoveEnteredFileCommand(L"Remove entered file"));

	IMenu* workingWithFilesSubmenu = new ConsoleMenu(L"Working with files options:");
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Show file size", showFileSizeSubmenu));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Create file", createFileSubmenu));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Copy file", copyFileSubmenu));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Relocate file", relocateFileSubmenu));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Rename file", renameFileSubmenu));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(L"Remove file", removeFileSubmenu));

	IMenu* searchSubstringSubmenu = new ConsoleMenu(L"Search substring options:");
	searchSubstringSubmenu->AddCommand(new SubstringInOnlyCurrentDirectoryCommand(L"Search in only current directory"));
	searchSubstringSubmenu->AddCommand(new SubstringInCurrentAndNestedDirectoriesCommand(
		L"Search in current and nested directories"));
	searchSubstringSubmenu->AddCommand(new SubstringInOnlyEnteredDirectoryCommand(L"Search in only entered directory"));
	searchSubstringSubmenu->AddCommand(new SubstringInEnteredAndNestedDirectoriesCommand(
		L"Search in entered and nested directories"));

	IMenu* mainMenu = new ConsoleMenu(L"File manager main menu:");
	mainMenu->AddCommand(new SubmenuExecuterCommand(L"Show directory content", showDirectoryContentSubmenu));
	mainMenu->AddCommand(new SubmenuExecuterCommand(L"Change current directory", changeCurrentDirectorySubmenu));
	mainMenu->AddCommand(new SubmenuExecuterCommand(L"Working with directories", workingWithDirectoriesSubmenu));
	mainMenu->AddCommand(new SubmenuExecuterCommand(L"Working with files", workingWithFilesSubmenu));
	mainMenu->AddCommand(new SubmenuExecuterCommand(L"Search substring", searchSubstringSubmenu));

	mainMenu->Start();

	delete showDirectoryContentSubmenu;
	delete changeCurrentDirectorySubmenu;
	delete showDirectorySizeSubmenu;
	delete createDirectorySubmenu;
	delete copyDirectorySubmenu;
	delete relocateDirectorySubmenu;
	delete renameDirectorySubmenu;
	delete removeDirectorySubmenu;
	delete workingWithDirectoriesSubmenu;
	delete showFileSizeSubmenu;
	delete createFileSubmenu;
	delete copyFileSubmenu;
	delete relocateFileSubmenu;
	delete renameFileSubmenu;
	delete removeFileSubmenu;
	delete workingWithFilesSubmenu;
	delete searchSubstringSubmenu;
	delete mainMenu;
}

void main()
{
	(void)_setmode(_fileno(stdout), _O_U16TEXT);
	(void)_setmode(_fileno(stdin), _O_U16TEXT);

	CreateMenuAndStartFileManager();
}