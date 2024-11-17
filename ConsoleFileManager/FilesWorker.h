#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include "IFilesWorker.h"
#include "IStringSpacesChecker.h"
#include "StringSpacesChecker.h"

class FilesWorker : public IFilesWorker
{
    IStringSpacesChecker* spacesChecker;

public:
    FilesWorker();
    ~FilesWorker();

    void Copy(const std::wstring& file, const std::wstring& destinationDirectory) const override;
    void Create(const std::wstring& destinationDirectory, const std::wstring& name) const override;
    unsigned long long GetSizeInBytes(const std::wstring& file) const override;
    void Relocate(const std::wstring& file, const std::wstring& destinationDirectory) const override;
    void Remove(const std::wstring& file) const override;
    void Rename(const std::wstring& file, const std::wstring& newName) const override;
};