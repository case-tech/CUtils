[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# RTTI Class

Runtime Type Information system for advanced type management.

## Features
- Runtime type identification
- Custom type name registration
- Type name retrieval
- Inheritance-friendly design
- Macro-based type declaration
- Integration with C++ type_index

## Basic API Methods
#### Class RTTI
- `virtual std::string GetTypeName() const = 0` - Returns type name (to implement)
- `static void RegisterType(const std::type_index& type_id_a, const std::string& type_name_a)` - Registers type
- `static std::string GetTypeNameById(const std::type_index& type_id_a)` - Gets type name by ID

#### Macro
- `RTTI_DECLARE_TYPE(type_a)` - Implements GetTypeName() for a class

## Example
#### cpp
```cpp
#include <CUtils/RTTI.hpp>

class GameObject : public CUtils::RTTI 
{
    RTTI_DECLARE_TYPE(GameObject)
    // Class implementation...
};

class Player : public GameObject 
{
    RTTI_DECLARE_TYPE(Player)
    // Class implementation...
};

int main()
{
    Player player_;
    
    // Get actual type name
    std::cout << "Player type: " << player_.GetTypeName() << std::endl;
    
    // Get type name from base pointer
    GameObject* obj_ = &player_;
    std::cout << "Object type: " << obj_->GetTypeName() << std::endl;
    
    // Get type name by ID
    auto type_name_ = RTTI::GetTypeNameById(std::type_index(typeid(Player)));
    std::cout << "Registered name: " << type_name_ << std::endl;
    
    return 0;
}
```

<a id="ru"></a>

# RTTI Класс
Система информации о типах во время выполнения (RTTI).

## Возможности
- Идентификация типов в runtime
- Регистрация пользовательских имен типов
- Получение имен типов
- Поддержка наследования
- Макросы для объявления типов
- Интеграция с std::type_index

## Основные методы API
#### Класс RTTI
- `virtual std::string GetTypeName() const = 0` - Возвращает имя типа (требует реализации)
- `static void RegisterType(const std::type_index& type_id_a, const std::string& type_name_a)` - Регистрирует тип
- `static std::string GetTypeNameById(const std::type_index& type_id_a)` - Получает имя типа по ID

#### Макрос
- `RTTI_DECLARE_TYPE(type_a)` - Реализует GetTypeName() для класса

## Пример использования
#### cpp
```cpp
#include <CUtils/RTTI.hpp>

class GameObject : public CUtils::RTTI 
{
    RTTI_DECLARE_TYPE(GameObject)
    // Реализация класса...
};

class Player : public GameObject 
{
    RTTI_DECLARE_TYPE(Player)
    // Реализация класса...
};

int main()
{
    Player player_;
    
    // Получить актуальное название типа
    std::cout << "Player тип: " << player_.GetTypeName() << std::endl;
    
    // Получить имя типа из базового указателя
    GameObject* obj_ = &player_;
    std::cout << "Object тип: " << obj_->GetTypeName() << std::endl;
    
    // Получить название типа по идентификатору
    auto type_name_ = RTTI::GetTypeNameById(std::type_index(typeid(Player)));
    std::cout << "Зарегистрированное имя: " << type_name_ << std::endl;
    
    return 0;
}
```