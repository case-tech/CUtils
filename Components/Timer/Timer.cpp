#include "Timer.hpp"

namespace CUtils
{
    Timer::Timer()
    {
        start_ = std::chrono::steady_clock::now();
        stop_ = std::chrono::steady_clock::now();
    }

    double Timer::GetMillisecondsElapsed()
    {
        if (is_running_)
        {
            auto elapsed_ = std::chrono::duration<double, std::milli>(
                            std::chrono::steady_clock::now() - start_);

            return elapsed_.count();
        } 
        else
        {
            auto elapsed_ = std::chrono::duration<double, std::milli>(stop_
                                                                    - start_);
            return elapsed_.count();
        }
    }

    void Timer::Restart()
    {
        is_running_ = true;
        start_ = std::chrono::steady_clock::now();
    }

    bool Timer::Stop()
    {
        if (!is_running_)
            return false;
        
        stop_ = std::chrono::steady_clock::now();
        is_running_ = false;
        
        return true;
    }

    bool Timer::Start()
    {
        if (is_running_)
            return false;
        
        start_ = std::chrono::steady_clock::now();
        is_running_ = true;
        
        return true;
    }
} // namespace CUtils
