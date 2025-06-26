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

#ifndef CUTILS_RANDOM_HPP
#define CUTILS_RANDOM_HPP

#include <random>
#include <chrono>

namespace CUtils
{
    class Random
    {
    public:
        Random();
        int RandomInt(int min_a, int max_a);
        int BinomialInt(int t_a, double p_a);
        int PoissonInt(double mean_a);
      
        double RandomDouble(double min_a, double max_a);
        double NormalDouble(double mean_a, double stddev_a);
      
        bool BernoulliBool(double p_a);

    private:
        std::mt19937 generator_;
    };
} // namespace CUtils
#endif
