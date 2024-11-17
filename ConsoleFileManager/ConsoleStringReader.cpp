#include "ConsoleStringReader.h"

std::wstring ConsoleStringReader::Read() const
{
	std::wstring result;

	std::wcout << " => ";
	getline(std::wcin, result);

	return result;
}