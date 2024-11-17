#pragma once

#include <iostream>

class IFilesWorker
{
public:
    virtual ~IFilesWorker() = default;

    virtual void Copy(const std::wstring& file, const std::wstring& destinationDirectory) const = 0;
    virtual void Create(const std::wstring& destinationDirectory, const std::wstring& name) const = 0;
    virtual unsigned long long GetSizeInBytes(const std::wstring& file) const = 0;
    virtual void Relocate(const std::wstring& file, const std::wstring& destinationDirectory) const = 0;
    virtual void Remove(const std::wstring& file) const = 0;
    virtual void Rename(const std::wstring& file, const std::wstring& newName) const = 0;
};