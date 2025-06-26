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

#ifndef CUTILS_FUSION_HPP
#define CUTILS_FUSION_HPP

#include <iostream>
#include <stdexcept>
#include <tuple>
#include <variant>
#include <vector>

namespace CUtils
{
    class Fusion
    {
    public:
        template <typename... Types>
        using Tuple = std::tuple<Types...>;

    private:
        template <typename... Types, std::size_t... Is>
        static auto GetByIndexHelper(const Tuple<Types...>& t_a,
                                     std::size_t index_a,
                                     std::index_sequence<Is...>)
        {
            using VariantType = std::variant<Types...>;
            VariantType result_;
            (((Is == index_a) ? (void)(result_ = std::get<Is>(t_a)) : (void)0), ...);
            return result_;
        }

    public:
        template <typename... Types1, typename... Types2>
        static auto Merge(const Tuple<Types1...>& t1_a,
                          const Tuple<Types2...>& t2_a)
        {
            return std::tuple_cat(t1_a, t2_a);
        }

        template <std::size_t Index, typename... Types>
        static decltype(auto) Get(const Tuple<Types...>& t_a)
        {
            return std::get<Index>(t_a);
        }

        template <typename T, typename... Types>
        static decltype(auto) GetByType(const Tuple<Types...>& t_a)
        {
            return std::get<T>(t_a);
        }

        template <typename... Types>
        static auto GetByIndex(const Tuple<Types...>& t_a, std::size_t index_a)
        {
            constexpr std::size_t size_ = sizeof...(Types);
            if (index_a >= size_)
            {
                throw std::out_of_range("Index out of range.");
            }

            return GetByIndexHelper(t_a,
                                    index_a,
                                    std::index_sequence_for<Types...> {});
        }

        template <typename... Types>
        static constexpr std::size_t Size(const Tuple<Types...>&)
        {
            return sizeof...(Types);
        }

        template <typename... Types1, typename... Types2>
        static bool AreEqual(const Tuple<Types1...>& t1_a,
                             const Tuple<Types2...>& t2_a)
        {
            if constexpr (sizeof...(Types1) != sizeof...(Types2))
            {
                return false;
            } 
            else
            {
                return t1_a == t2_a;
            }
        }

        template <typename TupleType, std::size_t... Indices>
        static void PrintHelper(const TupleType& t_a,
                                std::index_sequence<Indices...>)
        {
            std::size_t n_ = 0;
            ((std::cout << (n_++ == 0 ? "" : ", ") << std::get<Indices>(t_a)),
             ...);
        }

        template <typename... Types>
        static void Print(const Tuple<Types...>& t_a)
        {
            std::cout << "(";
            PrintHelper(t_a, std::index_sequence_for<Types...> {});
            std::cout << ")" << std::endl;
        }
    };
} // namespace CUtils
#endif