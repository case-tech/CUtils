[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# StringHelper Class

Advanced string manipulation utilities with extended functionality.

## Features
- Case conversion
- Whitespace trimming
- String splitting
- Substring operations
- Search and replace
- Type conversion
- Numeric extraction
- Operator overloading

## Basic API Methods
#### Class StringHelper
- `StringHelper(const std::string& str_a)` - Constructor from std::string
- `StringHelper(const char* str_a)` - Constructor from C-string
- `std::string ToLowerCase() const` - Converts to lower case
- `std::string ToUpperCase() const` - Converts to upper case
- `std::string Trim() const` - Removes leading/trailing whitespace
- `std::vector<std::string> Split(char delimiter_a) const` - Splits by delimiter
- `bool Contains(const std::string& substr_a) const` - Checks for substring
- `bool StartsWith(const std::string& prefix_a) const` - Checks prefix
- `bool EndsWith(const std::string& suffix_a) const` - Checks suffix
- `std::string Replace(const std::string& old_str_a, const std::string& new_str_a) const` - Replaces substring
- `int IndexOf(const std::string& substr_a) const` - Finds first occurrence
- `int LastIndexOf(const std::string& substr_a) const` - Finds last occurrence
- `std::string Substring(size_t start_a, size_t length_a) const` - Extracts substring
- `std::string ExtractNumericPart() const` - Extracts numbers and decimal point
- `std::optional<int> ToInt() const` - Converts to integer
- `std::optional<double> ToDouble() const` - Converts to double
- `std::optional<bool> ToBool() const` - Converts to boolean
- `operator std::string() const` - Conversion to std::string

## Example
#### cpp
```cpp
#include <CUtils/StringHelper.hpp>

int main()
{
    // Create from C-string
    CUtils::StringHelper str_("  Hello World! 123.45 ");
    
    // Basic operations
    std::string trimmed_ = str_.Trim();
    std::string upper_ = str_.ToUpperCase();
    bool contains_ = str_.Contains("World");
    
    // Type conversion
    auto number_ = str_.ExtractNumericPart(); // "123.45"
    auto dvalue_ = CUtils::StringHelper("3.14").ToDouble();
    
    // String manipulation
    std::string replaced_ = str_.Replace("World", "Universe");
    std::vector<std::string> parts_ = str_.Split(' ');
    
    // Operators
    CUtils::StringHelper name_ = "Alice";
    if (name_ == "Alice") 
	{
        std::cout << "Name matches" << std::endl;
    }
    
    return 0;
}
```

<a id="ru"></a>

# StringHelper Класс
Продвинутые утилиты для работы со строками.

## Возможности
- Преобразование регистра
- Удаление пробелов
- Разделение строк
- Операции с подстроками
- Поиск и замена
- Преобразование типов
- Извлечение чисел
- Перегрузка операторов

## Основные методы API
#### Класс StringHelper
- `StringHelper(const std::string& str_a)` - Конструктор из std::string
- `StringHelper(const char* str_a)` - Конструктор из C-строки
- `std::string ToLowerCase() const` - Преобразует в нижний регистр
- `std::string ToUpperCase() const` - Преобразует в верхний регистр
- `std::string Trim() const` - Удаляет начальные/конечные пробелы
- `std::vector<std::string> Split(char delimiter_a) const` - Разделяет по разделителю
- `bool Contains(const std::string& substr_a) const` - Проверяет наличие подстроки
- `bool StartsWith(const std::string& prefix_a) const` - Проверяет начало строки
- `bool EndsWith(const std::string& suffix_a) const` - Проверяет конец строки
- `std::string Replace(const std::string& old_str_a, const std::string& new_str_a) const` - Заменяет подстроку
- `int IndexOf(const std::string& substr_a) const` - Находит первое вхождение
- `int LastIndexOf(const std::string& substr_a) const` - Находит последнее вхождение
- `std::string Substring(size_t start_a, size_t length_a) const` - Извлекает подстроку
- `std::string ExtractNumericPart() const` - Извлекает числа и десятичную точку
- `std::optional<int> ToInt() const` - Преобразует в целое число
- `std::optional<double> ToDouble() const` - Преобразует в число с плавающей точкой
- `std::optional<bool> ToBool() const` - Преобразует в логическое значение
- `operator std::string() const` - Преобразование в std::string

## Пример использования
#### cpp
```cpp
#include <CUtils/StringHelper.hpp>

int main()
{
    // Создать из C-строки
    CUtils::StringHelper str_("  Hello World! 123.45 ");
    
    // Базовые операции
    std::string trimmed_ = str_.Trim();
    std::string upper_ = str_.ToUpperCase();
    bool contains_ = str_.Contains("World");
    
    // Преобразование типов
    auto number_ = str_.ExtractNumericPart(); // "123.45"
    auto dvalue_ = CUtils::StringHelper("3.14").ToDouble();
    
    // Манипулирование строками
    std::string replaced_ = str_.Replace("World", "Universe");
    std::vector<std::string> parts_ = str_.Split(' ');
    
    // Операторы
    CUtils::StringHelper name_ = "Alice";
    if (name_ == "Alice") 
	{
        std::cout << "Имя совпадает" << std::endl;
    }
    
    return 0;
}
```