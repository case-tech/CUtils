[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Options Class

Command-line arguments parser with help system.

## Features
- Command-line arguments parsing
- Option-value mapping
- Help system generation
- Option presence checking
- Simple value retrieval
- Support for both flags and key-value options

## Basic API Methods
#### Class Options
- `Options(int argc_a, char* argv_a[])` - Constructor with main arguments
- `void AddOption(const std::string& option_a, const std::string& description_a)` - Registers option with description
- `bool IsOptionSet(const std::string& option_a) const` - Checks if option is present
- `std::string GetOptionValue(const std::string& option_a) const` - Gets value for option
- `void PrintHelp() const` - Displays help message

## Example
#### cpp
```cpp
#include <CUtils/Options.hpp>

int main(int argc_a, char* argv_a[])
{
    CUtils::Options opts_(argc_a, argv_a);
    
    // Register supported options
    opts_.AddOption("-h", "Show help message");
    opts_.AddOption("-v", "Enable verbose mode");
    opts_.AddOption("-o", "Specify output file");
    
    // Check for help request
    if (opts_.IsOptionSet("-h"))
	{
        opts_.PrintHelp();
        return 0;
    }
    
    // Process options
    if (opts_.IsOptionSet("-v")) 
	{
        std::cout << "Verbose mode enabled" << std::endl;
    }
    
    std::string output_ = opts_.GetOptionValue("-o");
    if (!output_.empty()) 
	{
        std::cout << "Output file: " << output_ << std::endl;
    }
    
    return 0;
}
```

<a id="ru"></a>

# Options Класс
Парсер аргументов командной строки с системой помощи.

## Возможности
- Разбор аргументов командной строки
- Сопоставление опций и значений
- Генерация системы помощи
- Проверка наличия опций
- Простое получение значений
- Поддержка флагов и опций со значениями

## Основные методы API
#### Класс Options
- `Options(int argc_a, char* argv_a[])` - Конструктор с аргументами main
- `void AddOption(const std::string& option_a, const std::string& description_a)` - Регистрирует опцию с описанием
- `bool IsOptionSet(const std::string& option_a) const` - Проверяет наличие опции
- `std::string GetOptionValue(const std::string& option_a) const` - Получает значение опции
- `void PrintHelp() const` - Выводит справочное сообщение

## Пример использования
#### cpp
```cpp
#include <CUtils/Options.hpp>

int main(int argc_a, char* argv_a[])
{
    CUtils::Options opts_(argc_a, argv_a);
    
    // Регистрация поддерживаемых параметров
    opts_.AddOption("-h", "Show help message");
    opts_.AddOption("-v", "Enable verbose mode");
    opts_.AddOption("-o", "Specify output file");
    
    // Проверьте наличие запроса на помощь
    if (opts_.IsOptionSet("-h"))
	{
        opts_.PrintHelp();
        return 0;
    }
    
    // Параметры процесса
    if (opts_.IsOptionSet("-v")) 
	{
        std::cout << "Включен подробный режим" << std::endl;
    }
    
    std::string output_ = opts_.GetOptionValue("-o");
    if (!output_.empty()) 
	{
        std::cout << "Выходной файл: " << output_ << std::endl;
    }
    
    return 0;
}
```