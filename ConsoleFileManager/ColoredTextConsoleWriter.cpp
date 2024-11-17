#include "ColoredTextConsoleWriter.h"

ColoredTextConsoleWriter::ColoredTextConsoleWriter()
{
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ColoredTextConsoleWriter::Write(const std::wstring text, const int numericColorCode)
{
    SetConsoleTextAttribute(hConsoleOutput, numericColorCode);
    std::wcout << text;
    SetConsoleTextAttribute(hConsoleOutput, Constants::WhiteOnBlackTextCode);
}

void ColoredTextConsoleWriter::Write(const long long value, const int numericColorCode)
{
    SetConsoleTextAttribute(hConsoleOutput, numericColorCode);
    std::wcout << value;
    SetConsoleTextAttribute(hConsoleOutput, Constants::WhiteOnBlackTextCode);
}