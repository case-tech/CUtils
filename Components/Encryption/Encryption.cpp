#include "Encryption.hpp"
#include <stdexcept>

namespace CUtils
{
    Encryption::Encryption(Alg algorithm_a, const std::string& key_a)
                               : algorithm_(algorithm_a), key_(key_a)
    {
        if (algorithm_ == Alg::Vigenere && key_a.empty())
        {
            throw std::invalid_argument("Vigenere cipher requires a key.");
        }

        if (algorithm_ == Alg::XOR && key_a.empty())
        {
            throw std::invalid_argument("XOR cipher requires a key.");
        }

        if (algorithm_ == Alg::Transposition && key_a.empty())
        {
            throw std::invalid_argument("Transposition cipher requires a key.");
        }
    }

    std::string Encryption::Encrypt(const std::string& plain_text_a)
    {
        std::string result_;
        switch (algorithm_)
        {
        case Alg::Caesar: 
        {
            int shift_ = 3;
            for (char c_ : plain_text_a)
            {
                if (isalpha(c_))
                {
                    char base_ = islower(c_) ? 'a' : 'A';
                    result_ += (c_ - base_ + shift_) % 26 + base_;
                }
                else
                {
                    result_ += c_;
                }
            }
            break;
        }
        case Alg::Vigenere: 
        {
            for (size_t i_ = 0; i_ < plain_text_a.size(); ++i_)
            {
                char c_ = plain_text_a[i_];
                if (isalpha(c_))
                {
                    char base_ = islower(c_) ? 'a' : 'A';
                    char k_ = key_[i_ % key_.size()];
                    result_ += (c_ - base_ + (tolower(k_) - 'a')) % 26 + base_;
                }
                else
                {
                    result_ += c_;
                }
            }
            break;
        }
        case Alg::XOR: 
        {
            for (size_t i_ = 0; i_ < plain_text_a.size(); ++i_)
            {
                result_ += plain_text_a[i_] ^ key_[i_ % key_.size()];
            }
            break;
        }
        case Alg::Substitution: 
        {
            std::string substitution_ = "zyxwvutsrqponmlkjihgfedcba";
            for (char c_ : plain_text_a)
            {
                if (isalpha(c_))
                {
                    char base_ = islower(c_) ? 'a' : 'A';
                    result_ += substitution_[(c_ - base_)];
                }
                else
                {
                    result_ += c_;
                }
            }
            break;
        }
        case Alg::Transposition: 
        {
            size_t key_len_ = key_.size();
            for (size_t i_ = 0; i_ < key_len_; ++i_)
            {
                for (size_t j_ = i_; j_ < plain_text_a.size(); j_ += key_len_)
                {
                    result_ += plain_text_a[j_];
                }
            }
            break;
        }
        default:
            throw std::invalid_argument("Unsupported encryption algorithm.");
        }

        return result_;
    }

    std::string Encryption::Decrypt(const std::string& cipher_text_a)
    {
        std::string result_;
        switch (algorithm_)
        {
        case Alg::Caesar: 
        {
            int shift_ = 3;
            for (char c_ : cipher_text_a)
            {
                if (isalpha(c_))
                {
                    char base_ = islower(c_) ? 'a' : 'A';
                    result_ += (c_ - base_ - shift_ + 26) % 26 + base_;
                }
                else
                {
                    result_ += c_;
                }
            }
            break;
        }
        case Alg::Vigenere: 
        {
            for (size_t i_ = 0; i_ < cipher_text_a.size(); ++i_)
            {
                char c_ = cipher_text_a[i_];
                if (isalpha(c_))
                {
                    char base_ = islower(c_) ? 'a' : 'A';
                    char k_ = key_[i_ % key_.size()];
                    result_ += (c_ - base_ - (tolower(k_) - 'a') + 26) % 26 + base_;
                }
                else
                {
                    result_ += c_;
                }
            }
            break;
        }
        case Alg::XOR: 
        {
            for (size_t i_ = 0; i_ < cipher_text_a.size(); ++i_)
            {
                result_ += cipher_text_a[i_] ^ key_[i_ % key_.size()];
            }
            break;
        }
        case Alg::Substitution: 
        {
            std::string substitution_ = "zyxwvutsrqponmlkjihgfedcba";
            for (char c_ : cipher_text_a)
            {
                if (isalpha(c_))
                {
                    char base_ = islower(c_) ? 'a' : 'A';
                    result_ += (c_ - base_ + 26) % 26 + base_;
                }
                else
                {
                    result_ += c_;
                }
            }
            break;
        }
        case Alg::Transposition: 
        {
            size_t key_len_ = key_.size();
            size_t rows_ = (cipher_text_a.size() + key_len_ - 1) / key_len_;
            result_.resize(cipher_text_a.size(), ' ');
            for (size_t i_ = 0; i_ < key_len_; ++i_)
            {
                for (size_t j_ = 0; j_ < rows_; ++j_)
                {
                    if (j_ * key_len_ + i_ < cipher_text_a.size())
                    {
                        result_[j_ * key_len_ + i_] = cipher_text_a[i_ * rows_ + j_];
                    }
                }
            }
            break;
        }
        default:
            throw std::invalid_argument("Unsupported encryption algorithm.");
        }

        return result_;
    }
} // namespace CUtils