[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Singleton Class

Thread-safe singleton implementation template.

## Features
- Prevention of copying and assignment
- Automatic memory management
- Simple inheritance model
- C++11 standard compliance

## Basic API Methods
#### Template Class Singleton
- `static T& Instance()` - Returns single instance reference
- Protected constructor/destructor
- Deleted copy/assignment operators

## Example
#### cpp
```cpp
#include <CUtils/Singleton.hpp>

class Logger : public CUtils::Singleton<Logger> 
{
    friend class Singleton<Logger>;
    
protected:
    Logger() {}
    
public:
    void Log(const std::string& message_a) 
	{
        // Logging implementation...
    }
};

int main()
{
    // Access singleton instance
    Logger::Instance().Log("Application started");
    
    return 0;
}
```

<a id="ru"></a>

# Singleton Класс
Потокобезопасная реализация шаблона Singleton.

## Возможности
- Запрет копирования и присваивания
- Автоматическое управление памятью
- Простая модель наследования
- Соответствие стандарту C++11

## Основные методы API
- Шаблонный класс `Singleton`
- `static T& Instance()` - Возвращает ссылку на единственный экземпляр
- Защищенный конструктор/деструктор
- Удаленные операторы копирования/присваивания

## Пример использования
#### cpp
```cpp
#include <CUtils/Singleton.hpp>

class Logger : public CUtils::Singleton<Logger> 
{
    friend class Singleton<Logger>;
    
protected:
    Logger() {}
    
public:
    void Log(const std::string& message_a) 
	{
        // Logging реализация...
    }
};

int main()
{
    // Доступ к экземпляру Singleton
    Logger::Instance().Log("Программа выполнена");
    
    return 0;
}
```