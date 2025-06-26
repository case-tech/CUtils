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

#ifndef CUTILS_ENCRYPTION_HPP
#define CUTILS_ENCRYPTION_HPP

#include <string>

namespace CUtils
{
    enum class Alg
    {
        Caesar,
        Vigenere,
        XOR,
        Substitution,
        Transposition
    };

    class Encryption
    {
    public:
        Encryption(Alg algorithm_a, const std::string& key_a = "");

        std::string Encrypt(const std::string& plain_text_a);
        std::string Decrypt(const std::string& cipher_text_a);

    private:
        Alg algorithm_;
        std::string key_;
    };
} // namespace CUtils
#endif