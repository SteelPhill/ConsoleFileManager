#include "ConsoleMenu.h"

void ConsoleMenu::ExecuteCommand(const int selector)
{
	std::wcout << "Current directory:" << std::endl;
	coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);
	std::wcout << std::endl << std::endl;

	try
	{
		commands[selector]->Execute();
	}
	catch (const std::wstring& message)
	{
		system("cls");
		std::wcout << std::endl << "An error has occurred: " << message << std::endl << std::endl;
		system("pause");
	}
	catch (...)
	{
		system("cls");
		std::wcout << std::endl << "An error has occurred: unknown" << std::endl << std::endl;
		system("pause");
	}
}

ConsoleMenu::ConsoleMenu(const std::wstring& title)
{
	this->title = title;
	coloredTextWriter = new ColoredTextConsoleWriter();
	menuSelector = new ConsoleMenuSelector();
}

ConsoleMenu::~ConsoleMenu()
{
	for (const auto& command : commands)
		delete command;
	commands.clear();

	delete coloredTextWriter;
	delete menuSelector;
}

void ConsoleMenu::AddCommand(IMenuCommand* command)
{
	commands.push_back(command);
}

void ConsoleMenu::Start()
{
	int selector = 0;

	while (true)
	{
		system("cls");

		selector = menuSelector->Select(title, commands, selector);

		if (selector == commands.size())
			break;

		system("cls");

		if (selector != -1)
			ExecuteCommand(selector);
	}
}