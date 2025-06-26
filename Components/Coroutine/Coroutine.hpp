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

#ifndef CUTILS_COROUTINE_HPP
#define CUTILS_COROUTINE_HPP

#include <coroutine>
#include <iostream>

namespace CUtils
{
    class Coroutine
    {
    public:
        struct PromiseType
        {
            Coroutine GetReturnObject()
            {
                return Coroutine {Handle::from_promise(*this)};
            }

            std::suspend_always InitialSuspend() noexcept
            {
                return {};
            }

            std::suspend_always FinalSuspend() noexcept
            {
                return {};
            }

            void UnhandledException()
            {
                std::rethrow_exception(std::current_exception());
            }

            void ReturnVoid() noexcept
            {}
        };

        using Handle = std::coroutine_handle<PromiseType>;

    public:
        Coroutine() noexcept : handle_(nullptr)
        {}

        explicit Coroutine(Handle handle_a) : handle_(handle_a)
        {}

        Coroutine(const Coroutine&) = delete;
        Coroutine& operator=(const Coroutine&) = delete;

        Coroutine(Coroutine&& other_a) noexcept : handle_(other_a.handle_)
        {
            other_a.handle_ = nullptr;
        }

        Coroutine& operator=(Coroutine&& other_a) noexcept
        {
            if (this != &other_a)
            {
                if (handle_)
                {
                    handle_.destroy();
                }

                handle_ = other_a.handle_;
                other_a.handle_ = nullptr;
            }

            return *this;
        }

        ~Coroutine()
        {
            if (handle_)
            {
                handle_.destroy();
            }
        }

        bool Resume()
        {
            if (!handle_.done())
            {
                handle_.resume();
            }

            return !handle_.done();
        }

        bool Done() const
        {
            return handle_.done();
        }

    private:
        Handle handle_;
    };
} // namespace CUtils
#endif
