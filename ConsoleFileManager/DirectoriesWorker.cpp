#include "DirectoriesWorker.h"

std::vector<std::wstring> DirectoriesWorker::GetItems(const std::wstring& directory, const bool isGetDirectories) const
{
    std::vector<std::wstring> items;

    try
    {
        fs::directory_iterator itr(directory);
        fs::directory_entry entry;

        for (itr = begin(itr); itr != end(itr); ++itr)
        {
            entry = *itr;

            if (isGetDirectories && is_directory(entry.path()))
                items.push_back(L"[DIR.]" + entry.path().wstring());

            if (!isGetDirectories && is_regular_file(entry.path()))
                items.push_back(L"[FILE]" + entry.path().wstring());
        }
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to directory");
    }

    return items;
}

unsigned long long DirectoriesWorker::RecursiveGetSizeInBytes(const std::wstring& directory) const
{
    if (!fs::is_directory(directory))
        return 0;

    unsigned long long size = 0;

    try
    {
        fs::directory_iterator itr(directory);
        fs::directory_entry entry;

        for (itr = begin(itr); itr != end(itr); ++itr)
        {
            entry = *itr;

            if (fs::is_regular_file(entry.path()))
                size += file_size(entry.path());

            if (fs::is_directory(entry.path()))
                size += RecursiveGetSizeInBytes(entry.path().wstring());
        }
    }
    catch (const std::system_error&) { }

    return size;
}

std::wstring DirectoriesWorker::RecursiveSubstringSearch(const std::wstring& directory, const std::wstring& searchedText) const
{
    if (!fs::is_directory(directory))
        return L"";

    std::wstring result;
    std::wstring objectPath;
    fs::directory_iterator itr(directory);
    fs::directory_entry entry;

    if (fs::is_directory(directory))
    {
        for (itr = begin(itr); itr != end(itr); ++itr)
        {
            try
            {
                entry = *itr;
                objectPath = entry.path().wstring();

                if (fs::is_regular_file(objectPath))
                {
                    if (objectPath.find(searchedText) != std::wstring::npos)
                        result += L"[FILE]" + objectPath + L"\n";
                }
                else if (fs::is_directory(objectPath))
                {
                    if (objectPath.find(searchedText) != std::wstring::npos)
                        result += L"[DIR.]" + objectPath + L"\n";

                    result += RecursiveSubstringSearch(objectPath, searchedText);
                }
            }
            catch (const fs::filesystem_error&)
            {
                result += L"[NO ACCESS]" + objectPath + L"\n";
            }
        }
    }

    return result;
}

DirectoriesWorker::DirectoriesWorker()
{
    spacesChecker = new StringSpacesChecker();
}

DirectoriesWorker::~DirectoriesWorker()
{
    delete spacesChecker;
}

void DirectoriesWorker::Copy(const std::wstring& directoryToCopy, const std::wstring& destinationDirectory) const
{
    if (!fs::is_directory(directoryToCopy))
        throw std::wstring(L"Directory to copy does not exist");

    try
    {
        for (const auto& entry : fs::recursive_directory_iterator(directoryToCopy));
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to directory to copy or contain objects");
    }

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

    std::wstring copyDirectory = destinationDirectory + L"\\" + 
        directoryToCopy.substr(directoryToCopy.rfind(L"\\"), directoryToCopy.size());

    if (fs::is_directory(copyDirectory))
        throw std::wstring(L"Directory with same name already exists in selected directory");

    fs::create_directories(copyDirectory);

    std::error_code ec;
    fs::copy(directoryToCopy, copyDirectory, fs::copy_options::recursive, ec);
}

void DirectoriesWorker::Create(const std::wstring& destinationDirectory, const std::wstring& name) const
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
        throw std::wstring(L"New directory name is missing");

    std::wstring newDirectory = destinationDirectory + L"\\" + name;

    if (fs::is_directory(newDirectory))
        throw std::wstring(L"Directory with same name already exists in destination directory");

    fs::create_directories(newDirectory);

    if (!fs::is_directory(newDirectory))
        throw std::wstring(L"New directory has not been created");
}

std::vector<std::wstring> DirectoriesWorker::GetAllItems(const std::wstring& directory) const
{
    if (!fs::is_directory(directory))
        throw std::wstring(L"Directory does not exist");

    std::vector<std::wstring> result = GetDirectories(directory);
    std::vector<std::wstring> files = GetFiles(directory);

    result.insert(result.end(), files.begin(), files.end());

    return result;
}

std::vector<std::wstring> DirectoriesWorker::GetDirectories(const std::wstring& directory) const
{
    if (!fs::is_directory(directory))
        throw std::wstring(L"Directory does not exist");

    return GetItems(directory, true);
}

std::vector<std::wstring> DirectoriesWorker::GetFiles(const std::wstring& directory) const
{
    if (!fs::is_directory(directory))
        throw std::wstring(L"Directory does not exist");

    return GetItems(directory, false);
}

unsigned long long DirectoriesWorker::GetSizeInBytes(const std::wstring& directory) const
{
    if (!fs::is_directory(directory))
        throw std::wstring(L"Directory does not exist");

    try
    {
        fs::directory_iterator(directory);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to directory");
    }

    return RecursiveGetSizeInBytes(directory);
}

void DirectoriesWorker::Relocate(const std::wstring& directoryToRelocate, const std::wstring& destinationDirectory) const
{
    if (!fs::is_directory(directoryToRelocate))
        throw std::wstring(L"Directory to relocate does not exist");

    try
    {
        for (const auto& entry : fs::recursive_directory_iterator(directoryToRelocate));
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to directory to relocate or contain objects");
    }

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
        Copy(directoryToRelocate, destinationDirectory);
    }
    catch (const std::wstring& message) { throw message; }

    Remove(directoryToRelocate);
}

void DirectoriesWorker::Remove(const std::wstring& directory) const
{
    if (!fs::is_directory(directory))
        throw std::wstring(L"Directory to remove does not exist");

    try
    {
        for (const auto& entry : fs::recursive_directory_iterator(directory));
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to directory to remove or contain objects");
    }

    fs::remove_all(directory);
}

void DirectoriesWorker::Rename(const std::wstring& directoryToRename, const std::wstring& newName) const
{
    if (!fs::is_directory(directoryToRename))
        throw std::wstring(L"Directory to rename does not exist");

    if (newName.empty() || spacesChecker->Check(newName))
        throw std::wstring(L"New name is missing");

    std::wstring newDirectoryPath = directoryToRename.substr(0, directoryToRename.rfind(L"\\") + 1) + newName;

    try
    {
        fs::rename(directoryToRename, newDirectoryPath);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to directory to rename");
    }
}

std::wstring DirectoriesWorker::SubstringSearch(
    const std::wstring& directory,
    const std::wstring& searchedText,
    const bool isSearchOnlyInCurrent) const
{
    if (!fs::is_directory(directory))
        throw std::wstring(L"Directory does not exist");

    try
    {
        fs::directory_iterator(directory);
    }
    catch (const fs::filesystem_error&)
    {
        throw std::wstring(L"No access to directory");
    }

    if (searchedText.empty() || spacesChecker->Check(searchedText))
        throw std::wstring(L"Searched text is missing");

    if (isSearchOnlyInCurrent)
    {
        std::wstring result;
        std::wstring objectPath;
        fs::directory_iterator itr(directory);
        fs::directory_entry entry;

        for (itr = begin(itr); itr != end(itr); ++itr)
        {
            entry = *itr;
            objectPath = entry.path().wstring();

            if (objectPath.find(searchedText) != std::wstring::npos)
            {
                if (fs::is_directory(objectPath))
                    result += L"[DIR.]";

                if (fs::is_regular_file(objectPath))
                    result += L"[FILE]";

                result += objectPath + L"\n";
            }
        }

        return result;
    }

    return RecursiveSubstringSearch(directory, searchedText);
}