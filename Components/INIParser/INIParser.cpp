#include "INIParser.hpp"

namespace CUtils
{
    INIParser::INIParser(const std::string& filename_a) : filename_(filename_a)
    {}

    bool INIParser::Load()
    {
        std::ifstream file_(filename_);
        if (!file_.is_open())
        {
            return false;
        }

        std::string line_;
        std::string current_section_;
        while (std::getline(file_, line_))
        {
            _Trim(line_);
            if (line_.empty() || line_[0] == ';')
                continue;

            if (line_[0] == '[')
            {
                size_t end_ = line_.find(']');
                if (end_ != std::string::npos)
                {
                    current_section_ = line_.substr(1, end_ - 1);
                    _Trim(current_section_);
                }
            }
            else
            {
                size_t equal_sign_ = line_.find('=');
                if (equal_sign_ != std::string::npos && 
                    !current_section_.empty())
                {
                    std::string key_ = line_.substr(0, equal_sign_);
                    std::string value_ = line_.substr(equal_sign_ + 1);
                    _Trim(key_);
                    _Trim(value_);
                    data_[current_section_][key_] = value_;
                }
            }
        }

        return true;
    }

    bool INIParser::Save() const
    {
        std::ofstream file_(filename_);
        if (!file_.is_open())
        {
            return false;
        }

        for (const auto& section_ : data_)
        {
            file_ << "[" << section_.first << "]\n";
            for (const auto& key_value_ : section_.second)
            {
                file_ << key_value_.first << "=" << key_value_.second << "\n";
            }
        }

        return true;
    }

    std::string INIParser::GetValue(const std::string& section_a,
                                    const std::string& key_a) const
    {
        auto sec_it_ = data_.find(section_a);
        if (sec_it_ != data_.end())
        {
            auto key_it_ = sec_it_->second.find(key_a);
            if (key_it_ != sec_it_->second.end())
            {
                return key_it_->second;
            }
        }

        return "";
    }

    void INIParser::SetValue(const std::string& section_a,
                             const std::string& key_a,
                             const std::string& value_a)
    {
        data_[section_a][key_a] = value_a;
    }

    std::vector<std::string> INIParser::GetSections() const
    {
        std::vector<std::string> sections_;
        for (const auto& section_ : data_)
        {
            sections_.push_back(section_.first);
        }

        return sections_;
    }

    std::map<std::string, std::string> INIParser::GetKeys(
                             const std::string& section_a) const
    {
        auto sec_it_ = data_.find(section_a);
        if (sec_it_ != data_.end())
        {
            return sec_it_->second;
        }

        return {};
    }

    void INIParser::_Trim(std::string& str_a) const
    {
        size_t first_ = str_a.find_first_not_of(' ');
        size_t last_  = str_a.find_last_not_of(' ');
        str_a = (first_ == std::string::npos)
                 ? ""
                 : str_a.substr(first_, last_ - first_ + 1);
    }
} // namespace CUtils
