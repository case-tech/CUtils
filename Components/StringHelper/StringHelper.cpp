#include "StringHelper.hpp"

namespace CUtils
{
    StringHelper::StringHelper(const std::string& str_a) : data_(str_a)
    {}

    StringHelper::StringHelper(const char* str_a) : data_(str_a)
    {}

    std::string StringHelper::ToLowerCase() const
    {
        std::string result_ = data_;
        std::transform(result_.begin(), result_.end(), result_.begin(), ::tolower);
        return result_;
    }

    std::string StringHelper::ToUpperCase() const
    {
        std::string result_ = data_;
        std::transform(result_.begin(), result_.end(), result_.begin(), ::toupper);
        return result_;
    }

    std::string StringHelper::Trim() const
    {
        std::string result_ = data_;
        result_.erase(result_.begin(),
                      std::find_if(result_.begin(),
                                   result_.end(),
                                   [](unsigned char ch_) 
                                   {
                                       return !std::isspace(ch_);
                                   }));

        result_.erase(std::find_if(result_.rbegin(),
                                   result_.rend(),
                                   [](unsigned char ch_) 
                                   {
                                       return !std::isspace(ch_);
                                   }).base(), result_.end());

        return result_;
    }

    std::vector<std::string> StringHelper::Split(char delimiter_a) const
    {
        std::vector<std::string> tokens_;
        std::string token_;
        for (char ch_ : data_)
        {
            if (ch_ == delimiter_a)
            {
                if (!token_.empty())
                {
                    tokens_.push_back(token_);
                    token_.clear();
                }
            }
            else
            {
                token_ += ch_;
            }
        }

        if (!token_.empty())
        {
            tokens_.push_back(token_);
        }

        return tokens_;
    }

    bool StringHelper::Contains(const std::string& substr_a) const
    {
        return data_.find(substr_a) != std::string::npos;
    }

    bool StringHelper::StartsWith(const std::string& prefix_a) const
    {
        return data_.compare(0, prefix_a.length(), prefix_a) == 0;
    }

    bool StringHelper::EndsWith(const std::string& suffix_a) const
    {
        if (suffix_a.length() > data_.length())
            return false;
        
        return data_.compare(data_.length() - suffix_a.length(),
                             suffix_a.length(),
                             suffix_a) == 0;
    }

    std::string StringHelper::Replace(const std::string& old_str_a,
                                      const std::string& new_str_a) const
    {
        std::string result_ = data_;
        size_t pos_ = 0;
        while ((pos_ = result_.find(old_str_a, pos_)) != std::string::npos)
        {
            result_.replace(pos_, old_str_a.length(), new_str_a);
            pos_ += new_str_a.length();
        }

        return result_;
    }

    int StringHelper::IndexOf(const std::string& substr_a) const
    {
        size_t pos_ = data_.find(substr_a);
        return pos_ == std::string::npos ? -1 : static_cast<int>(pos_);
    }

    int StringHelper::LastIndexOf(const std::string& substr_a) const
    {
        size_t pos_ = data_.rfind(substr_a);
        return pos_ == std::string::npos ? -1 : static_cast<int>(pos_);
    }

    std::string StringHelper::Substring(size_t start_a, size_t length_a) const
    {
        if (start_a >= data_.length())
        {
            throw std::out_of_range("Start index out of range.");
        }

        return data_.substr(start_a, length_a);
    }

    std::string StringHelper::ExtractNumericPart() const
    {
        std::string result_;
        bool found_decimal_ = false;

        for (char ch_ : data_)
        {
            if (std::isdigit(ch_))
            {
                result_ += ch_;
            }
            else if (ch_ == '.' && !found_decimal_)
            {
                result_ += ch_;
                found_decimal_ = true;
            }
        }

        return result_;
    }

    bool StringHelper::IsEmpty() const
    {
        return data_.empty();
    }

    size_t StringHelper::Length() const
    {
        return data_.length();
    }

    StringHelper& StringHelper::operator=(const std::string& str_a)
    {
        data_ = str_a;
        return *this;
    }

    StringHelper& StringHelper::operator=(const char* str_a)
    {
        data_ = str_a;
        return *this;
    }

    bool StringHelper::operator==(const StringHelper& other_a) const
    {
        return data_ == other_a.data_;
    }

    bool StringHelper::operator!=(const StringHelper& other_a) const
    {
        return data_ != other_a.data_;
    }

    StringHelper::operator std::string() const
    {
        return data_;
    }

    std::optional<int> StringHelper::ToInt() const
    {
        try
        {
            size_t pos_;
            int result_ = std::stoi(data_, &pos_);
            if (pos_ != data_.length())
            {
                return std::nullopt;
            }

            return result_;
        }
        catch (const std::invalid_argument&)
        {
            return std::nullopt;
        }
        catch (const std::out_of_range&)
        {
            return std::nullopt;
        }
    }

    std::optional<double> StringHelper::ToDouble() const
    {
        try
        {
            size_t pos_;
            double result_ = std::stod(data_, &pos_);
            if (pos_ != data_.length())
            {
                return std::nullopt;
            }

            return result_;
        }
        catch (const std::invalid_argument&)
        {
            return std::nullopt;
        }
        catch (const std::out_of_range&)
        {
            return std::nullopt;
        }
    }

    std::optional<bool> StringHelper::ToBool() const
    {
        std::string lower_str_ = ToLowerCase();

        if (lower_str_ == "true" || lower_str_ == "1")
        {
            return true;
        } 
        else if (lower_str_ == "false" || lower_str_ == "0")
        {
            return false;
        } 
        else
        {
            return std::nullopt;
        }
    }
} // namespace CUtils
