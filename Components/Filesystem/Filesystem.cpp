#include "Filesystem.hpp"

namespace CUtils
{
    bool Filesystem::CreateDirectory(const std::string& path_a)
    {
        return std::filesystem::create_directory(path_a);
    }

    bool Filesystem::Remove(const std::string& path_a)
    {
        return std::filesystem::remove(path_a);
    }

    bool Filesystem::Rename(const std::string& old_path_a,
                            const std::string& new_path_a)
    {
        try
        {
            std::filesystem::rename(old_path_a, new_path_a);
            return true;
        } 
        catch (const std::filesystem::filesystem_error& e_)
        {
            return false;
        }
    }

    bool Filesystem::Exists(const std::string& path_a) const
    {
        return std::filesystem::exists(path_a);
    }

    std::vector<std::string> Filesystem::ListDirectory(
            const std::string& path_a) const
    {
        std::vector<std::string> entries_;
        if (!IsDirectory(path_a))
        {
            return entries_;
        }

        for (const auto& entry_ : std::filesystem::directory_iterator(path_a))
        {
            entries_.push_back(entry_.path().string());
        }

        return entries_;
    }

    std::string Filesystem::GetAbsolutePath(const std::string& path_a) const
    {
        return std::filesystem::absolute(path_a).string();
    }

    bool Filesystem::IsDirectory(const std::string& path_a) const
    {
        return std::filesystem::is_directory(path_a);
    }

    bool Filesystem::IsFile(const std::string& path_a) const
    {
        return std::filesystem::is_regular_file(path_a);
    }

    uintmax_t Filesystem::FileSize(const std::string& path_a) const
    {
        if (!IsFile(path_a))
        {
            throw std::runtime_error("Path is not a file: " + path_a);
        }

        return std::filesystem::file_size(path_a);
    }

    bool Filesystem::Copy(const std::string& from_a,
                          const std::string& to_a,
                          bool recursive_a)
    {
        try
        {
            if (recursive_a && IsDirectory(from_a))
            {
                _CopyDirectoryRecursive(from_a, to_a);
            } 
            else
            {
                std::filesystem::copy(from_a, to_a);
            }

            return true;
        } 
        catch (const std::filesystem::filesystem_error& e_)
        {
            return false;
        }
    }

    void Filesystem::_CopyDirectoryRecursive(
            const std::filesystem::path& from_a,
            const std::filesystem::path& to_a)
    {
        std::filesystem::create_directories(to_a);
        for (const auto& entry_ : std::filesystem::directory_iterator(from_a))
        {
            const auto& new_from_ = entry_.path();
            const auto& new_to_ = to_a / entry_.path().filename();
            if (std::filesystem::is_directory(new_from_))
            {
                _CopyDirectoryRecursive(new_from_, new_to_);
            } 
            else
            {
                std::filesystem::copy(new_from_, new_to_);
            }
        }
    }
} // namespace CUtils