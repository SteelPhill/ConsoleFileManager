#include "StringSpacesChecker.h"

bool StringSpacesChecker::Check(const std::wstring& text) const
{
    for (auto i = 0; i < (int)text.size(); i++)
        if (text[i] != ' ')
            return false;

    return true;
}