#include "ConsoleMenuSelector.h"

ConsoleMenuSelector::ConsoleMenuSelector()
{
    menuWriter = new ConsoleMenuWriter();
}

ConsoleMenuSelector::~ConsoleMenuSelector()
{
    delete menuWriter;
}

int ConsoleMenuSelector::Select(const std::wstring& title, const std::vector<IMenuCommand*> commands, int& selector) const
{
    int key;
    int itemsNumber = (int)commands.size();

    do
    {
        system("cls");

        menuWriter->Write(title, commands, selector);

        do
        {
            key = _getch();

        } while (key != Constants::Enter && key != Constants::Esc && key != Constants::UpArrow && key != Constants::DownArrow);

        if (key == Constants::Enter)
            return selector;

        else if (key == Constants::Esc)
            return itemsNumber;

        else if (key == Constants::UpArrow && selector != 0)
            selector--;

        else if (key == Constants::DownArrow && selector != itemsNumber)
            selector++;

    } while (true);
}

std::wstring ConsoleMenuSelector::Select(const std::wstring& title, const std::vector<std::wstring> items) const
{
    int key;
    int selector = 0;
    int itemsNumber = (int)items.size();

    do
    {
        system("cls");

        menuWriter->Write(title, items, selector);

        do
        {
            key = _getch();

        } while (key != Constants::Enter && key != Constants::Esc && key != Constants::UpArrow && key != Constants::DownArrow);

        if (key == Constants::Enter && selector != itemsNumber)
            return items[selector];

        else if (key == Constants::Enter && selector == itemsNumber || key == Constants::Esc)
            return L"";

        else if (key == Constants::UpArrow && selector != 0)
            selector--;

        else if (key == Constants::DownArrow && selector != itemsNumber)
            selector++;

    } while (true);
}