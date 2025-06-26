#include "Multithread.hpp"

namespace CUtils
{
    Multithread::~Multithread()
    {
        JoinAll();
    }

    void Multithread::Run()
    {
        for (auto& task_ : tasks_)
        {
            threads_.push_back(std::thread([task_]() 
            {
                try
                {
                    task_();
                }
                catch (const std::exception& e_)
                {
                    std::cerr << "Error in the thread: " << e_.what()
                              << std::endl;
                }
            }));
        }
    }

    void Multithread::JoinAll()
    {
        for (auto& t_ : threads_)
        {
            if (t_.joinable())
            {
                t_.join();
            }
        }
    }

    void Multithread::JoinOne(std::thread& t_a)
    {
        if (t_a.joinable())
        {
            t_a.join();
        }
    }

    void Multithread::CancelAll()
    {
        for (auto& t_ : threads_)
        {
            if (t_.joinable())
            {
                t_.detach();
            }
        }

        threads_.clear();
    }
} // namespace CUtils