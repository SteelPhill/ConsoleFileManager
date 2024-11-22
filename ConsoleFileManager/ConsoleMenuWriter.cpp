#include "ConsoleMenuWriter.h"

ConsoleMenuWriter::ConsoleMenuWriter()
{
    coloredTextWriter = new ColoredTextConsoleWriter();
    spacesChecker = new StringSpacesChecker();
}

ConsoleMenuWriter::~ConsoleMenuWriter()
{
    delete coloredTextWriter;
    delete spacesChecker;
}

void ConsoleMenuWriter::Write(const std::wstring& title, const std::vector<IMenuCommand*> commands, int& selector) const
{
    auto itemsNumber = (int)commands.size();

    system("cls");

    std::wcout << "Current directory:" << std::endl;
    coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);

    if (!spacesChecker->Check(title))
        std::wcout << std::endl << std::endl << " " << title << std::endl << std::endl;

    for (const auto& command : commands)
    {
        std::wstring selectedItem = command->GetDescription();

        std::wcout << " ";

        if (selector != itemsNumber && commands[selector]->GetDescription() == command->GetDescription())
            coloredTextWriter->Write(selectedItem, Constants::BlackOnWhiteTextCode);
        else
            std::wcout << selectedItem;

        std::wcout << std::endl;
    }

    std::wcout << std::endl << " ";

    if (selector == itemsNumber)
        coloredTextWriter->Write(L"Exit", Constants::BlackOnWhiteTextCode);
    else
        std::wcout << "Exit";

    std::wcout << std::endl;
}

void ConsoleMenuWriter::Write(const std::wstring& title, const std::vector<std::wstring> items, int& selector) const
{
    auto itemsNumber = (int)items.size();

    system("cls");

    std::wcout << "Current directory:" << std::endl;
    coloredTextWriter->Write(CurrentDirectory::Path, Constants::BlackOnWhiteTextCode);

    std::wcout << std::endl << std::endl << " " << title << std::endl << std::endl;

    for (const auto& item : items)
    {
        std::wstring selectedItem = item.c_str();

        std::wcout << " ";

        if (selector != itemsNumber && items[selector] == selectedItem)
            coloredTextWriter->Write(selectedItem, Constants::BlackOnWhiteTextCode);
        else
            std::wcout << selectedItem;

        std::wcout << std::endl;
    }

    std::wcout << std::endl << " ";

    if (selector == itemsNumber)
        coloredTextWriter->Write(L"Exit", Constants::BlackOnWhiteTextCode);
    else
        std::wcout << "Exit";

    std::wcout << std::endl;
}