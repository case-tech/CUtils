[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Filesystem Class

Cross-platform filesystem operations wrapper.

## Features
- Directory creation and removal
- File/directory renaming
- Existence checking
- Directory listing
- Path resolution
- File type detection
- File size retrieval
- Recursive directory copying
- Error-safe operations

## Basic API Methods
#### Class Filesystem
- `bool CreateDirectory(const std::string& path_a)` - Creates directory
- `bool Remove(const std::string& path_a)` - Removes file or empty directory
- `bool Rename(const std::string& old_path_a, const std::string& new_path_a)` - Renames/moves file/directory
- `bool Exists(const std::string& path_a) const` - Checks path existence
- `bool Copy(const std::string& from_a, const std::string& to_a, bool recursive_a = false)` - Copies files/directories
- `std::vector<std::string> ListDirectory(const std::string& path_a) const` - Lists directory contents
- `std::string GetAbsolutePath(const std::string& path_a) const` - Converts to absolute path
- `bool IsDirectory(const std::string& path_a) const` - Checks if path is directory
- `bool IsFile(const std::string& path_a) const` - Checks if path is regular file
- `uintmax_t FileSize(const std::string& path_a) const` - Gets file size

## Example
#### cpp
```cpp
#include <CUtils/Filesystem.hpp>

int main()
{
    CUtils::Filesystem fs_;
    
    // Create directory structure
    fs_.CreateDirectory("data");
    fs_.CreateDirectory("data/images");
    
    // Copy files recursively
    fs_.Copy("source/assets", "data/assets", true);
    
    // List directory contents
    auto files_ = fs_.ListDirectory("data");
    for (const auto& file_ : files_) 
    {
        std::cout << file_ << std::endl;
    }
    
    // Get file information
    if (fs_.IsFile("data/config.ini")) 
    {
        auto size_ = fs_.FileSize("data/config.ini");
        std::cout << "Config size: " << size_ << " bytes" << std::endl;
    }
    
    // Cleanup
    fs_.Remove("data");
    return 0;
}
```

<a id="ru"></a>
# Filesystem Класс
Кросс-платформенная обертка для операций с файловой системой.

## Возможности
- Создание и удаление директорий
- Переименование файлов/директорий
- Проверка существования
- Получение списка файлов
- Преобразование путей
- Определение типа объектов
- Получение размера файлов
- Рекурсивное копирование
- Безопасная обработка ошибок

## Основные методы API
#### Класс Filesystem
- `bool CreateDirectory(const std::string& path_a)` - Создает директорию
- `bool Remove(const std::string& path_a)` - Удаляет файл или пустую директорию
- `bool Rename(const std::string& old_path_a, const std::string& new_path_a)` - Переименовывает/перемещает объект
- `bool Exists(const std::string& path_a) const` - Проверяет существование пути
- `bool Copy(const std::string& from_a, const std::string& to_a, bool recursive_a = false)` - Копирует файлы/директории
- `std::vector<std::string> ListDirectory(const std::string& path_a) const` - Возвращает содержимое директории
- `std::string GetAbsolutePath(const std::string& path_a) const` - Возвращает абсолютный путь
- `bool IsDirectory(const std::string& path_a) const` - Проверяет, является ли путь директорией
- `bool IsFile(const std::string& path_a) const` - Проверяет, является ли путь файлом
- `uintmax_t FileSize(const std::string& path_a) const` - Возвращает размер файла

## Пример использования
#### cpp
```cpp
#include <CUtils/Filesystem.hpp>

int main()
{
    CUtils::Filesystem fs_;
    
    // Создать структуру каталогов
    fs_.CreateDirectory("data");
    fs_.CreateDirectory("data/images");
    
    // Рекурсивное копирование файлов
    fs_.Copy("source/assets", "data/assets", true);
    
    // Перечислить содержимое каталога
    auto files_ = fs_.ListDirectory("data");
    for (const auto& file_ : files_) 
    {
        std::cout << file_ << std::endl;
    }
    
    // Получить информацию о файле
    if (fs_.IsFile("data/config.ini")) 
    {
        auto size_ = fs_.FileSize("data/config.ini");
        std::cout << "Размер конфигурации: " << size_ << " bytes" << std::endl;
    }
    
    // Очистка
    fs_.Remove("data");
    return 0;
}
```