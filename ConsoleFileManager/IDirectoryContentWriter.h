#pragma once

#include <iostream>

class IDirectoryContentWriter
{
public:
	virtual ~IDirectoryContentWriter() = default;

	virtual void Write(const std::wstring& directory) const = 0;
};