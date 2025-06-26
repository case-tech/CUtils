#include "NoisePerlin.hpp"

namespace CUtils
{
    NoisePerlin::NoisePerlin(unsigned int seed_a)
    {
        permutation_.resize(PERM_SIZE * 2);
        for (int i_ = 0; i_ < PERM_SIZE; ++i_)
        {
            permutation_[i_] = i_;
        }

        if (seed_a > 0)
        {
            srand(seed_a);
            for (int i_ = PERM_SIZE - 1; i_ > 0; --i_)
            {
                int j_ = rand() % (i_ + 1);
                std::swap(permutation_[i_], permutation_[j_]);
            }
        }

        for (int i_ = 0; i_ < PERM_SIZE; ++i_)
        {
            permutation_[i_ + PERM_SIZE] = permutation_[i_];
        }
    }

    double NoisePerlin::_Fade(double t_a) const
    {
        return t_a * t_a * t_a * (t_a * (t_a * 6 - 15) + 10);
    }

    double NoisePerlin::_Lerp(double t_a, double a_a, double b_a) const
    {
        return a_a + t_a * (b_a - a_a);
    }

    double NoisePerlin::_Grad(int hash_a, double x_a, double y_a) const
    {
        int h_ = hash_a & 3;
        double u_ = h_ < 2 ? x_a : y_a;
        double v_ = h_ < 2 ? y_a : x_a;

        return ((h_ & 1) ? -u_ : u_) + ((h_ & 2) ? -v_ : v_);
    }

    double NoisePerlin::Noise(double x_a, double y_a) const
    {
        int xi_ = static_cast<int>(std::floor(x_a)) & 255;
        int yi_ = static_cast<int>(std::floor(y_a)) & 255;

        double xf_ = x_a - std::floor(x_a);
        double yf_ = y_a - std::floor(y_a);

        double u_ = _Fade(xf_);
        double v_ = _Fade(yf_);

        int aa_ = permutation_[permutation_[xi_] + yi_];
        int ab_ = permutation_[permutation_[xi_] + yi_ + 1];
        int ba_ = permutation_[permutation_[xi_ + 1] + yi_];
        int bb_ = permutation_[permutation_[xi_ + 1] + yi_ + 1];

        double x1_ = _Lerp(u_,
                           _Grad(permutation_[aa_], xf_, yf_),
                           _Grad(permutation_[ba_], xf_ - 1, yf_));
        
        double x2_ = _Lerp(u_,
                           _Grad(permutation_[ab_], xf_, yf_ - 1),
                           _Grad(permutation_[bb_], xf_ - 1, yf_ - 1));

        return (_Lerp(v_, x1_, x2_) + 1.0) / 2.0;
    }
} // namespace CUtils
