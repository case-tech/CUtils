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

#ifndef CUTILS_NOISEPERLIN_HPP
#define CUTILS_NOISEPERLIN_HPP

#include <iostream>
#include <vector>

namespace CUtils
{
    class NoisePerlin
    {
    public:
        NoisePerlin(unsigned int seed_a = 0);
        double Noise(double x_a, double y_a) const;

    private:
        double _Fade(double t_a) const;
        double _Lerp(double t_a, double a_a, double b_a) const;
        double _Grad(int hash_a, double x_a, double y_a) const;

    private:
        static const int PERM_SIZE = 256;
        std::vector<int> permutation_;
    };
} // namespace CUtils
#endif
