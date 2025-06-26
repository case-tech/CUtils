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

#ifndef CUTILS_SINGLETON_HPP
#define CUTILS_SINGLETON_HPP

#include <memory>
#include <mutex>

namespace CUtils
{
    template <typename T>
    class Singleton
    {
    public:
        static T& Instance()
        {
            std::call_once(init_flag_, []() 
                    { instance_ptr_.reset(new T()); });
            
            return *instance_ptr_;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    protected:
        Singleton() = default;
        virtual ~Singleton() = default;

    private:
        static std::unique_ptr<T> instance_ptr_;
        static std::once_flag init_flag_;
    };

    template <typename T>
    std::unique_ptr<T> Singleton<T>::instance_ptr_ = nullptr;

    template <typename T>
    std::once_flag Singleton<T>::init_flag_;
} // namespace CUtils
#endif
