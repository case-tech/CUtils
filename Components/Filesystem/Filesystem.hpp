/*
The MIT License (MIT)
Copyright (c) 2025 Case Technologies

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ 

#ifndef CUTILS_FILESYSTEM_HPP
#define CUTILS_FILESYSTEM_HPP

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

namespace CUtils
{
    class Filesystem
    {
    public:
        Filesystem() = default;
        ~Filesystem() = default;

        bool CreateDirectory(const std::string& path_a);
        bool Remove(const std::string& path_a);
        bool Rename(const std::string& old_path_a, const std::string& new_path_a);
        bool Exists(const std::string& path_a) const;
        
        bool Copy(const std::string& from_a,
                  const std::string& to_a,
                  bool recursive_a = false);

        std::vector<std::string> ListDirectory(const std::string& path_a) const;
        std::string GetAbsolutePath(const std::string& path_a) const;

        bool IsDirectory(const std::string& path_a) const;
        bool IsFile(const std::string& path_a) const;

        uintmax_t FileSize(const std::string& path_a) const;

    private:
        void _CopyDirectoryRecursive(const std::filesystem::path& from_a,
                                     const std::filesystem::path& to_a);
    };
} // namespace CUtils
#endif