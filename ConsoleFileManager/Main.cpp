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
	showDirectoryContentSubmenu->AddCommand(new ShowContentsCurrentDirectoryCommand());
	showDirectoryContentSubmenu->AddCommand(new ShowContentsEnteredDirectoryCommand());

	IMenu* changeCurrentDirectorySubmenu = new ConsoleMenu(L"Change current directory options");
	changeCurrentDirectorySubmenu->AddCommand(new ChangeCurrentDirectoryToPreviousCommand());
	changeCurrentDirectorySubmenu->AddCommand(new ChangeCurrentDirectoryToSelectedCommand());
	changeCurrentDirectorySubmenu->AddCommand(new ChangeCurrentDirectoryToEnteredCommand());

	IMenu* showDirectorySizeSubmenu = new ConsoleMenu(L"Show directory size options:");
	showDirectorySizeSubmenu->AddCommand(new ShowCurrentDirectorySizeCommand());
	showDirectorySizeSubmenu->AddCommand(new ShowSelectedDirectorySizeCommand());
	showDirectorySizeSubmenu->AddCommand(new ShowEnteredDirectorySizeCommand());

	IMenu* createDirectorySubmenu = new ConsoleMenu(L"Create directory options:");
	createDirectorySubmenu->AddCommand(new CreateDirectoryInCurrentDirectoryCommand());
	createDirectorySubmenu->AddCommand(new CreateDirectoryInEnteredDirectoryCommand());

	IMenu* copyDirectorySubmenu = new ConsoleMenu(L"Copy directory options:");
	copyDirectorySubmenu->AddCommand(new CopyDirectoryFromCurrentDirectoryCommand());
	copyDirectorySubmenu->AddCommand(new CopyEnteredDirectoryCommand());

	IMenu* relocateDirectorySubmenu = new ConsoleMenu(L"Relocate directory options:");
	relocateDirectorySubmenu->AddCommand(new RelocateDirectoryFromCurrentDirectoryCommand());
	relocateDirectorySubmenu->AddCommand(new RelocateEnteredDirectoryCommand());

	IMenu* renameDirectorySubmenu = new ConsoleMenu(L"Rename directory options:");
	renameDirectorySubmenu->AddCommand(new RenameDirectoryFromCurrentDirectoryCommand());
	renameDirectorySubmenu->AddCommand(new RenameEnteredDirectoryCommand());

	IMenu* removeDirectorySubmenu = new ConsoleMenu(L"Remove directory options:");
	removeDirectorySubmenu->AddCommand(new RemoveDirectoryFromCurrentDirectoryCommand());
	removeDirectorySubmenu->AddCommand(new RemoveEnteredDirectoryCommand());

	IMenu* workingWithDirectoriesSubmenu = new ConsoleMenu(L"Working with directories options:");
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(showDirectorySizeSubmenu, L"Show directory size"));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(createDirectorySubmenu, L"Create directory"));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(copyDirectorySubmenu, L"Copy directory"));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(relocateDirectorySubmenu, L"Relocate directory"));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(renameDirectorySubmenu, L"Rename directory"));
	workingWithDirectoriesSubmenu->AddCommand(new SubmenuExecuterCommand(removeDirectorySubmenu, L"Remove directory"));

	IMenu* showFileSizeSubmenu = new ConsoleMenu(L"Show file size options:");
	showFileSizeSubmenu->AddCommand(new ShowSelectedFileSizeCommand());
	showFileSizeSubmenu->AddCommand(new ShowEnteredFileSizeCommand());

	IMenu* createFileSubmenu = new ConsoleMenu(L"Create file options:");
	createFileSubmenu->AddCommand(new CreateFileInCurrentDirectoryCommand());
	createFileSubmenu->AddCommand(new CreateFileInEnteredDirectoryCommand());

	IMenu* copyFileSubmenu = new ConsoleMenu(L"Copy file options:");
	copyFileSubmenu->AddCommand(new CopyFileFromCurrentDirectoryCommand());
	copyFileSubmenu->AddCommand(new CopyEnteredFileCommand());

	IMenu* relocateFileSubmenu = new ConsoleMenu(L"Relocate file options:");
	relocateFileSubmenu->AddCommand(new RelocateFileFromCurrentDirectoryCommand());
	relocateFileSubmenu->AddCommand(new RelocateEnteredFileCommand());

	IMenu* renameFileSubmenu = new ConsoleMenu(L"Rename file options:");
	renameFileSubmenu->AddCommand(new RenameFileFromCurrentDirectoryCommand());
	renameFileSubmenu->AddCommand(new RenameEnteredFileCommand());

	IMenu* removeFileSubmenu = new ConsoleMenu(L"Remove file options:");
	removeFileSubmenu->AddCommand(new RemoveFileFromCurrentDirectoryCommand());
	removeFileSubmenu->AddCommand(new RemoveEnteredFileCommand());

	IMenu* workingWithFilesSubmenu = new ConsoleMenu(L"Working with files options:");
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(showFileSizeSubmenu, L"Show file size"));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(createFileSubmenu, L"Create file"));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(copyFileSubmenu, L"Copy file"));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(relocateFileSubmenu, L"Relocate file"));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(renameFileSubmenu, L"Rename file"));
	workingWithFilesSubmenu->AddCommand(new SubmenuExecuterCommand(removeFileSubmenu, L"Remove file"));

	IMenu* searchSubstringSubmenu = new ConsoleMenu(L"Search substring options:");
	searchSubstringSubmenu->AddCommand(new SubstringInOnlyCurrentDirectoryCommand());
	searchSubstringSubmenu->AddCommand(new SubstringInCurrentAndNestedDirectoriesCommand());
	searchSubstringSubmenu->AddCommand(new SubstringInOnlyEnteredDirectoryCommand());
	searchSubstringSubmenu->AddCommand(new SubstringInEnteredAndNestedDirectoriesCommand());

	IMenu* mainMenu = new ConsoleMenu(L"File manager main menu:");
	mainMenu->AddCommand(new SubmenuExecuterCommand(showDirectoryContentSubmenu, L"Show directory content"));
	mainMenu->AddCommand(new SubmenuExecuterCommand(changeCurrentDirectorySubmenu, L"Change current directory"));
	mainMenu->AddCommand(new SubmenuExecuterCommand(workingWithDirectoriesSubmenu, L"Working with directories"));
	mainMenu->AddCommand(new SubmenuExecuterCommand(workingWithFilesSubmenu, L"Working with files"));
	mainMenu->AddCommand(new SubmenuExecuterCommand(searchSubstringSubmenu, L"Search substring"));

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