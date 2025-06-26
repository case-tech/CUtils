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

#ifndef CUTILS_UNITTESTS_HPP
#define CUTILS_UNITTESTS_HPP

#include <string>
#include <functional>
#include <iostream>

namespace CUtils
{
#define ASSERT_TRUE(condition)                                                 \
    if (!(condition))                                                          \
    {                                                                          \
        std::cerr << "ASSERT_TRUE failed: " #condition << std::endl;           \
        return;                                                                \
    }

#define ASSERT_FALSE(condition)                                                \
    if (condition)                                                             \
    {                                                                          \
        std::cerr << "ASSERT_FALSE failed: " #condition << std::endl;          \
        return;                                                                \
    }

#define ASSERT_EQ(expected, actual)                                            \
    if ((expected) != (actual))                                                \
    {                                                                          \
        std::cerr << "ASSERT_EQ failed: " #expected " != " #actual             \
                  << std::endl;                                                \
        return;                                                                \
    }

#define ASSERT_NE(val1, val2)                                                  \
    if ((val1) == (val2))                                                      \
    {                                                                          \
        std::cerr << "ASSERT_NE failed: " #val1 " == " #val2 << std::endl;     \
        return;                                                                \
    }

#define ASSERT_LT(val1, val2)                                                  \
    if (!((val1) < (val2)))                                                    \
    {                                                                          \
        std::cerr << "ASSERT_LT failed: " #val1 " >= " #val2 << std::endl;     \
        return;                                                                \
    }

#define ASSERT_LE(val1, val2)                                                  \
    if (!((val1) <= (val2)))                                                   \
    {                                                                          \
        std::cerr << "ASSERT_LE failed: " #val1 " > " #val2 << std::endl;      \
        return;                                                                \
    }

#define ASSERT_GT(val1, val2)                                                  \
    if (!((val1) > (val2)))                                                    \
    {                                                                          \
        std::cerr << "ASSERT_GT failed: " #val1 " <= " #val2 << std::endl;     \
        return;                                                                \
    }

#define ASSERT_GE(val1, val2)                                                  \
    if (!((val1) >= (val2)))                                                   \
    {                                                                          \
        std::cerr << "ASSERT_GE failed: " #val1 " < " #val2 << std::endl;      \
        return;                                                                \
    }

#define ASSERT_STREQ(expected_str, actual_str)                                 \
    if (std::strcmp((expected_str), (actual_str)) != 0)                        \
    {                                                                          \
        std::cerr << "ASSERT_STREQ failed: " #expected_str " != " #actual_str  \
                  << std::endl;                                                \
        return;                                                                \
    }

#define ASSERT_STRNE(str1, str2)                                               \
    if (std::strcmp((str1), (str2)) == 0)                                      \
    {                                                                          \
        std::cerr << "ASSERT_STRNE failed: " #str1 " == " #str2 << std::endl;  \
        return;                                                                \
    }

#define ASSERT_STRCASEEQ(expected_str, actual_str)                             \
    if (_stricmp((expected_str), (actual_str)) != 0)                           \
    {                                                                          \
        std::cerr << "ASSERT_STRCASEEQ failed: " #expected_str                 \
                     " != " #actual_str                                        \
                  << std::endl;                                                \
        return;                                                                \
    }

#define ASSERT_STRCASENE(str1, str2)                                           \
    if (_stricmp((str1), (str2)) == 0)                                         \
    {                                                                          \
        std::cerr << "ASSERT_STRCASENE failed: " #str1 " == " #str2            \
                  << std::endl;                                                \
        return;                                                                \
    }

#define EXPECT_TRUE(condition)                                                 \
    if (!(condition))                                                          \
    {                                                                          \
        std::cerr << "EXPECT_TRUE failed: " #condition << std::endl;           \
    }
#define EXPECT_FALSE(condition)                                                \
    if (condition)                                                             \
    {                                                                          \
        std::cerr << "EXPECT_FALSE failed: " #condition << std::endl;          \
    }

#define ASSERT_THROW(statement, exception_type)                                \
    try                                                                        \
    {                                                                          \
        statement;                                                             \
        std::cerr                                                              \
                << "ASSERT_THROW failed: Expected exception " #exception_type  \
                << std::endl;                                                  \
        return;                                                                \
    } catch (const exception_type&)                                            \
    {}

#define ASSERT_NO_THROW(statement)                                             \
    try                                                                        \
    {                                                                          \
        statement;                                                             \
    } catch (...)                                                              \
    {                                                                          \
        std::cerr << "ASSERT_NO_THROW failed: Unexpected exception thrown"     \
                  << std::endl;                                                \
        return;                                                                \
    }

#define SUCCEED() (std::cout << "Test succeeded" << std::endl)
#define FAIL() (std::cerr << "Test failed" << std::endl; return)

#define UTEST(test_case_name, test_name)                                       \
    void test_case_name##_##test_name();                                       \
    struct test_case_name##_##test_name##_registrar                            \
    {                                                                          \
        test_case_name##_##test_name##_registrar()                             \
        {                                                                      \
            tests.emplace_back(#test_case_name,                                \
                               #test_name,                                     \
                               test_case_name##_##test_name);                  \
        }                                                                      \
    } test_case_name##_##test_name##_instance;                                 \
    void test_case_name##_##test_name()

    struct Test
    {
        std::string test_case_name_;
        std::string test_name_;
        std::function<void()> func_;

        Test(const std::string& case_name_a,
             const std::string& name_a,
             const std::function<void()>& f_a)
            : test_case_name_(case_name_a), test_name_(name_a), func_(f_a)
        {}
    };

    static std::vector<Test> registry_;

    inline int RUN_ALL_TESTS()
    {
        int passed_ = 0;
        int failed_ = 0;
        for (auto& test_ : registry_)
        {
            std::cout << "Running test " << test_.test_case_name_ << "."
                      << test_.test_name_ << std::endl;
            try
            {
                test_.func_();
                std::cout << "[  PASSED  ] " << test_.test_case_name_ << "."
                          << test_.test_name_ << std::endl;
                passed_++;
            } catch (...)
            {
                std::cerr << "[  FAILED  ] " << test_.test_case_name_ << "."
                          << test_.test_name_ << std::endl;
                failed_++;
            }
        }

        std::cout << "Tests passed: " << passed_
                  << ", Tests failed: " << failed_ << std::endl;

        return failed_ > 0 ? 1 : 0;
    }
} // namespace CUtils
#endif
