#pragma once

#include <iostream>
#include <vector>

class IDirectoriesWorker
{
public:
    virtual ~IDirectoriesWorker() = default;

    virtual void Copy(const std::wstring& directoryToCopy, const std::wstring& destinationDirectory) const = 0;
    virtual void Create(const std::wstring& destinationDirectory, const std::wstring& name) const = 0;
    virtual std::vector<std::wstring> GetAllItems(const std::wstring& directory) const = 0;
    virtual std::vector<std::wstring> GetDirectories(const std::wstring& directory) const = 0;
    virtual std::vector<std::wstring> GetFiles(const std::wstring& directory) const = 0;
    virtual unsigned long long GetSizeInBytes(const std::wstring& directory) const = 0;
    virtual void Relocate(const std::wstring& directoryToRelocate, const std::wstring& destinationDirectory) const = 0;
    virtual void Remove(const std::wstring& directory) const = 0;
    virtual void Rename(const std::wstring& directoryToRename, const std::wstring& newName) const = 0;
    virtual std::wstring SubstringSearch(const std::wstring& directory, const std::wstring& searchedText, const bool isSearchOnlyInCurrent) const = 0;
};