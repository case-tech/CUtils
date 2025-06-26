[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Encryption Class

Cryptographic utilities for common encryption algorithms.

## Features
- Multiple encryption algorithms support
- Symmetric encryption/decryption
- Key-based security
- Exception handling for invalid operations
- Simple API for common cryptographic needs

## Supported Algorithms
- `Caesar`: Classic shift cipher (3 positions)
- `Vigenere`: Poly-alphabetic substitution cipher
- `XOR`: Bitwise XOR cipher
- `Substitution`: Alphabet reversal cipher
- `Transposition`: Columnar transposition cipher

## Basic API Methods
#### Class Encryption
- `Encryption(Alg algorithm_a, const std::string& key_a = "")` - Constructor with algorithm selection and optional key
- `std::string Encrypt(const std::string& plain_text_a)` - Encrypts plaintext
- `std::string Decrypt(const std::string& cipher_text_a)` - Decrypts ciphertext

## Example
#### cpp
```cpp
#include <CUtils/Encryption.hpp>

int main()
{
    // Vigenere cipher with key
    CUtils::Encryption vigenere_(CUtils::Alg::Vigenere, "secret");
    std::string encrypted_ = vigenere.Encrypt("HelloWorld");
    std::string decrypted_ = vigenere.Decrypt(encrypted);
    
    // XOR cipher with key
    CUtils::Encryption xor_cipher_(CUtils::Alg::XOR, "\x1f");
    std::string xor_enc_ = xor_cipher_.Encrypt("SensitiveData");
    
    // Caesar cipher (no key required)
    CUtils::Encryption caesar_(CUtils::Alg::Caesar);
    std::string caesar_msg_ = caesar_.Encrypt("ABCxyz");
    
    return 0;
}
```

<a id="ru"></a>
# Encryption Класс
Криптографические утилиты для распространенных алгоритмов шифрования.

## Возможности
- Поддержка нескольких алгоритмов шифрования
- Симметричное шифрование/дешифрование
- Ключевая безопасность
- Обработка ошибок для недопустимых операций
- Простой API для базовых криптографических задач

## Поддерживаемые алгоритмы
- `Caesar`: Классический шифр сдвига (3 позиции)
- `Vigenere`: Полиалфавитный подстановочный шифр
- `XOR`: Побитовый XOR-шифр
- `Substitution`: Шифр с обратным алфавитом
- `Transposition`: Столбцовый метод перестановки

## Основные методы API
#### Класс Encryption
- `Encryption(Alg algorithm_a, const std::string& key_a = "")` - Конструктор с выбором алгоритма и опциональным ключом

- `std::string Encrypt(const std::string& plain_text_a)` - Шифрование открытого текста
- `std::string Decrypt(const std::string& cipher_text_a)` - Дешифрование зашифрованного текста

## Пример использования
#### cpp
```cpp
#include <CUtils/Encryption.hpp>

int main()
{
    // Шифр Виженера с ключом
    CUtils::Encryption vigenere_(CUtils::Alg::Vigenere, "secret");
    std::string encrypted_ = vigenere.Encrypt("HelloWorld");
    std::string decrypted_ = vigenere.Decrypt(encrypted);
    
    // Исключающий шифр с ключом
    CUtils::Encryption xor_cipher_(CUtils::Alg::XOR, "\x1f");
    std::string xor_enc_ = xor_cipher_.Encrypt("SensitiveData");
    
    // Шифр Цезаря (ключ не требуется)
    CUtils::Encryption caesar_(CUtils::Alg::Caesar);
    std::string caesar_msg_ = caesar_.Encrypt("ABCxyz");
    
    return 0;
}
```