#include "FilesWorker.h"

FilesWorker::FilesWorker()
{
    spacesChecker = new StringSpacesChecker();
}

FilesWorker::~FilesWorker()
{
    delete spacesChecker;
}

void FilesWorker::Copy(const std::wstring& file, const std::wstring& destinationDirectory) const
{
    if (!fs::is_regular_file(file))
        throw std::wstring(L"File to copy does not exist");

    if (!fs::is_directory(destinationDirectory))
        throw std::wstring(L"Destination directory does not exist");

    try
    {
        fs::directory_iterator(destinationDirectory);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to destination directory");
    }

    std::wstring copiedFilePath = destinationDirectory + L"\\" + file.substr(file.rfind(L"\\"), file.size());

    if (fs::is_regular_file(copiedFilePath))
        throw std::wstring(L"File with same name already exists in selected directory");

    try
    {
        fs::copy_file(file, copiedFilePath);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to file to copy");
    }
}

void FilesWorker::Create(const std::wstring& destinationDirectory, const std::wstring& name) const
{
    if (!fs::is_directory(destinationDirectory))
        throw std::wstring(L"Destination directory does not exist");

    try
    {
        fs::directory_iterator(destinationDirectory);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to destination directory");
    }

    if (name.empty() || spacesChecker->Check(name))
        throw std::wstring(L"New file name is missing");

    std::wstring newFile = destinationDirectory + L"\\" + name;

    if (fs::is_regular_file(newFile))
        throw std::wstring(L"File with same name already exists in destination directory");

    std::ofstream file;
    file.open(newFile);
    if (!file.is_open())
        throw std::wstring(L"New file has not been created");
    file.close();
}

unsigned long long FilesWorker::GetSizeInBytes(const std::wstring& file) const
{
    if (!fs::is_regular_file(file))
        throw std::wstring(L"File does not exist");

    return fs::file_size(file);
}

void FilesWorker::Relocate(const std::wstring& file, const std::wstring& destinationDirectory) const
{
    if (!fs::is_regular_file(file))
        throw std::wstring(L"File to relocate does not exist");

    if (!fs::is_directory(destinationDirectory))
        throw std::wstring(L"Destination directory does not exist");

    try
    {
        fs::directory_iterator(destinationDirectory);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to destination directory");
    }

    try
    {
        Copy(file, destinationDirectory);
    }
    catch (const std::wstring&)
    {
        throw std::wstring(L"No access to file to relocate or file with same name already exists in selected directory");
    }

    Remove(file);
}

void FilesWorker::Remove(const std::wstring& file) const
{
    if (!fs::is_regular_file(file))
        throw std::wstring(L"File to remove does not exist");

    try
    {
        fs::remove(file);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to file to remove");
    }
}

void FilesWorker::Rename(const std::wstring& file, const std::wstring& newName) const
{
    if (!fs::is_regular_file(file))
        throw std::wstring(L"File to rename does not exist");

    if (newName.empty() || spacesChecker->Check(newName))
        throw std::wstring(L"New file name is missing");

    std::wstring newFilePath = file.substr(0, file.rfind(L"\\") + 1) + newName;

    try
    {
        fs::rename(file, newFilePath);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to file to rename");
    }
}