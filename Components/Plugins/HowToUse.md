[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Plugins Class

Cross-platform plugin management system for dynamic library loading.

## Features
- Dynamic library loading (Windows/Linux/macOS)
- Plugin lifecycle management
- Standardized plugin interface
- Automatic resource cleanup
- Error handling
- Unified execution model

## Core Components
#### PluginInterface
- `virtual void Execute() = 0` - Entry point for plugin execution

#### Plugins
- `bool LoadPlugin(const std::string& plugin_path_a)` - Loads plugin from file
- Automatic unloading in destructor

## Basic API Methods
#### Class Plugins
- `Plugins()` - Constructor
- `~Plugins()` - Destructor (auto-unloads all plugins)
- `bool LoadPlugin(const std::string& plugin_path_a)` - Loads and executes plugin

## Example
#### cpp (Main Application)
```cpp
#include <CUtils/Plugins.hpp>

int main()
{
    CUtils::Plugins manager_;
    
    // Load Windows plugin
    #if defined(_WIN32) || defined(_WIN64)
    manager_.LoadPlugin("my_plugin.dll");
    #else
    // Load Linux/macOS plugin
    manager_.LoadPlugin("libmy_plugin.so");
    #endif
    
    return 0;
}
```

#### cpp (Plugin Implementation)
```cpp
#include <CUtils/Plugins.hpp>

class MyPlugin : public CUtils::PluginInterface 
{
public:
    void Execute() override 
	{
        std::cout << "MyPlugin executed!" << std::endl;
    }
};

extern "C" CUtils::PluginInterface* createPlugin() 
{
    return new MyPlugin();
}
```

<a id="ru"></a>

# Plugins Класс
Кросс-платформенная система управления плагинами для загрузки динамических библиотек.

## Возможности
- Загрузка динамических библиотек (Windows/Linux/macOS)
- Управление жизненным циклом плагинов
- Стандартизированный интерфейс плагинов
- Автоматическое освобождение ресурсов
- Обработка ошибок
- Унифицированная модель выполнения

## Основные компоненты
#### PluginInterface
- `virtual void Execute() = 0` - Точка входа для выполнения плагина

#### Plugins
- `bool LoadPlugin(const std::string& plugin_path_a)` - Загружает плагин из файла
- Автоматическая выгрузка в деструкторе

## Основные методы API
#### Класс Plugins
- `Plugins()` - Конструктор
- `~Plugins()` - Деструктор (автоматически выгружает плагины)
- `bool LoadPlugin(const std::string& plugin_path_a)` - Загружает и выполняет плагин

## Пример использования
#### cpp (Основное приложение)
```cpp
#include <CUtils/Plugins.hpp>

int main()
{
    CUtils::Plugins manager_;
    
    // Загрузка Windows плагина
    #if defined(_WIN32) || defined(_WIN64)
    manager_.LoadPlugin("my_plugin.dll");
    #else
    // Загрузка Linux/macOS плагина
    manager_.LoadPlugin("libmy_plugin.so");
    #endif
    
    return 0;
}
```

#### cpp (Plugin Implementation)
```cpp
#include <CUtils/Plugins.hpp>

class MyPlugin : public CUtils::PluginInterface 
{
public:
    void Execute() override 
	{
        std::cout << "MyPlugin выполнен!" << std::endl;
    }
};

extern "C" CUtils::PluginInterface* createPlugin() 
{
    return new MyPlugin();
}
```