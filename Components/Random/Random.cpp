#include "Random.hpp"

namespace CUtils
{
    Random::Random()
    {
        unsigned seed_ =
                std::chrono::system_clock::now().time_since_epoch().count();
        
        generator_.seed(seed_);
    }

    int Random::RandomInt(int min_a, int max_a)
    {
        std::uniform_int_distribution<int> distribution_(min_a, max_a);
        return distribution_(generator_);
    }

    double Random::RandomDouble(double min_a, double max_a)
    {
        std::uniform_real_distribution<double> distribution_(min_a, max_a);
        return distribution_(generator_);
    }

    double Random::NormalDouble(double mean_a, double stddev_a)
    {
        std::normal_distribution<double> distribution_(mean_a, stddev_a);
        return distribution_(generator_);
    }

    int Random::BinomialInt(int t_a, double p_a)
    {
        std::binomial_distribution<int> distribution_(t_a, p_a);
        return distribution_(generator_);
    }

    bool Random::BernoulliBool(double p_a)
    {
        std::bernoulli_distribution distribution_(p_a);
        return distribution_(generator_);
    }

    int Random::PoissonInt(double mean_a)
    {
        std::poisson_distribution<int> distribution_(mean_a);
        return distribution_(generator_);
    }
} // namespace CUtils
