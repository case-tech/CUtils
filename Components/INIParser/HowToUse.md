[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# INIParser Class

INI file parsing and serialization utilities.

## Features
- INI file loading/saving
- Section-based configuration
- Key-value pair management
- Comment support (; prefix)
- Automatic whitespace trimming
- Section/key enumeration
- Simple read/write interface

## Basic API Methods
#### Class INIParser
- `INIParser(const std::string& filename_a)` - Constructor with filename
- `bool Load()` - Loads INI file
- `bool Save() const` - Saves changes to INI file
- `std::string GetValue(const std::string& section_a, const std::string& key_a) const` - Gets value by section and key
- `void SetValue(const std::string& section_a, const std::string& key_a, const std::string& value_a)` - Sets value
- `std::vector<std::string> GetSections() const` - Gets all section names
- `std::map<std::string, std::string> GetKeys(const std::string& section_a) const` - Gets all key-value pairs in section

## Example
#### cpp
```cpp
#include <CUtils/INIParser.hpp>

int main()
{
    // Create parser and load file
    CUtils::INIParser parser_("config.ini");
    if (!parser_.Load()) 
    {
        std::cerr << "Failed to load config.ini" << std::endl;
        return 1;
    }

    // Read values
    std::string title_ = parser_.GetValue("App", "Title");
    int width_ = std::stoi(parser_.GetValue("Window", "Width"));
    
    // Modify values
    parser_.SetValue("Window", "Fullscreen", "true");
    
    // Add new section and key
    parser_.SetValue("Audio", "Volume", "80");
    
    // List sections
    auto sections_ = parser_.GetSections();
    for (const auto& section_ : sections_) 
    {
        std::cout << "Section: " << section_ << std::endl;
    }
    
    // Save changes
    if (!parser_.Save()) 
    {
        std::cerr << "Failed to save config" << std::endl;
    }
    
    return 0;
}
```

<a id="ru"></a>

# INIParser Класс
Утилиты для чтения и записи INI-файлов.

## Возможности
- Загрузка/сохранение INI-файлов
- Работа с секциями конфигурации
- Управление ключами-значениями
- Поддержка комментариев (префикс ;)
- Автоматическое удаление пробелов
- Перечисление секций и ключей
- Простой интерфейс чтения/записи

## Основные методы API
#### Класс INIParser
- `INIParser(const std::string& filename_a)` - Конструктор с именем файла
- `bool Load()` - Загружает INI-файл
- `bool Save() const` - Сохраняет изменения в файл
- `std::string GetValue(const std::string& section_a, const std::string& key_a) const` - Получает значение по секции и ключу
- `void SetValue(const std::string& section_a, const std::string& key_a, const std::string& value_a)` - Устанавливает значение
- `std::vector<std::string> GetSections() const` - Возвращает все имена секций
- `std::map<std::string, std::string> GetKeys(const std::string& section_a) const` - Возвращает все пары ключ-значение в секции

## Пример использования
#### cpp
```cpp
#include <CUtils/INIParser.hpp>

int main()
{
    // Создайть парсер и загрузить файл
    CUtils::INIParser parser_("config.ini");
    if (!parser_.Load()) 
    {
        std::cerr << "Failed to load config.ini" << std::endl;
        return 1;
    }

    // Прочитать значения
    std::string title_ = parser_.GetValue("App", "Title");
    int width_ = std::stoi(parser_.GetValue("Window", "Width"));
    
    // Модифицировать значения
    parser_.SetValue("Window", "Fullscreen", "true");
    
    // Добавить новую секцию и ключ
    parser_.SetValue("Audio", "Volume", "80");
    
    // Список секций
    auto sections_ = parser_.GetSections();
    for (const auto& section_ : sections_) 
    {
        std::cout << "Секция: " << section_ << std::endl;
    }
    
    // Сохранить изменения
    if (!parser_.Save()) 
    {
        std::cerr << "Не удалось сохранить конфигурацию" << std::endl;
    }
    
    return 0;
}
```