#include "Options.hpp"
#include <algorithm>

namespace CUtils
{
    Options::Options(int argc_a, char* argv_a[])
    {
        for (int i_ = 0; i_ < argc_a; ++i_)
        {
            args_.emplace_back(argv_a[i_]);
        }
    }

    void Options::AddOption(const std::string& option_a,
                            const std::string& description_a)
    {
        options_[option_a] = description_a;
    }

    bool Options::IsOptionSet(const std::string& option_a) const
    {
        return std::find(args_.begin(), 
                         args_.end(), option_a) != args_.end();
    }

    std::string Options::GetOptionValue(const std::string& option_a) const
    {
        auto it_ = std::find(args_.begin(), args_.end(), option_a);
        if (it_ != args_.end() && ++it_ != args_.end())
        {
            return *it_;
        }

        return "";
    }

    void Options::PrintHelp() const
    {
        std::cout << "Available options:\n";
        for (const auto& opt_ : options_)
        {
            std::cout << "  " << opt_.first << ": " << opt_.second << "\n";
        }
    }
} // namespace CUtils