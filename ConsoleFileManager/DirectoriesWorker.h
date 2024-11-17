#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include "IDirectoriesWorker.h"
#include "IStringSpacesChecker.h"
#include "StringSpacesChecker.h"

class DirectoriesWorker : public IDirectoriesWorker
{
    IStringSpacesChecker* spacesChecker;

    std::vector<std::wstring> GetItems(const std::wstring& directory, const bool isGetDirectories) const;
    unsigned long long RecursiveGetSizeInBytes(const std::wstring& directory) const;
    std::wstring RecursiveSubstringSearch(const std::wstring& directory, const std::wstring& searchedText) const;

public:
    DirectoriesWorker();
    ~DirectoriesWorker();

    void Copy(const std::wstring& directoryToCopy, const std::wstring& destinationDirectory) const override;
    void Create(const std::wstring& destinationDirectory, const std::wstring& name) const override;
    std::vector<std::wstring> GetAllItems(const std::wstring& directory) const override;
    std::vector<std::wstring> GetDirectories(const std::wstring& directory) const override;
    std::vector<std::wstring> GetFiles(const std::wstring& directory) const override;
    unsigned long long GetSizeInBytes(const std::wstring& directory) const override;
    void Relocate(const std::wstring& directoryToRelocate, const std::wstring& destinationDirectory) const override;
    void Remove(const std::wstring& directory) const override;
    void Rename(const std::wstring& directoryToRename, const std::wstring& newName) const override;
    std::wstring SubstringSearch(const std::wstring& directory, const std::wstring& searchedText, const bool isSearchOnlyInCurrent) const override;
};