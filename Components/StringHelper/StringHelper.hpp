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

#ifndef CUTILS_STRINGHELPER_HPP
#define CUTILS_STRINGHELPER_HPP

#include <string>
#include <vector>
#include <optional>
#include <algorithm>
#include <stdexcept>

namespace CUtils
{
    class StringHelper
    {
    public:
        StringHelper() = default;
        StringHelper(const std::string& str_a);
        StringHelper(const char* str_A);

        std::string ToLowerCase() const;
        std::string ToUpperCase() const;
        std::string Trim() const;
        
        std::vector<std::string> Split(char delimiter_a) const;
        bool Contains(const std::string& substr_a) const;
        bool StartsWith(const std::string& prefix_a) const;
        bool EndsWith(const std::string& suffix_a) const;
        
        std::string Replace(const std::string& old_str_a,
                            const std::string& new_str_a) const;
        
        int IndexOf(const std::string& substr_a) const;
        int LastIndexOf(const std::string& substr_a) const;
        
        std::string Substring(size_t start_a,
                              size_t length_a = std::string::npos) const;
        
        bool IsEmpty() const;
        size_t Length() const;
        std::string ExtractNumericPart() const;

        StringHelper& operator=(const std::string& str_a);
        StringHelper& operator=(const char* str_a);
        
        bool operator==(const StringHelper& other_a) const;
        bool operator!=(const StringHelper& other_a) const;

        std::optional<int>    ToInt() const;
        std::optional<double> ToDouble() const;
        std::optional<bool>   ToBool() const;

        operator std::string() const;

    private:
        std::string data_;
    };
} // namespace CUtis
#endif
