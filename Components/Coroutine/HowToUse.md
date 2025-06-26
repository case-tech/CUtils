[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Coroutine Class

C++20 coroutine wrapper for asynchronous operations management.

## Features
- Coroutine lifecycle management
- Safe move semantics
- Exception propagation
- Integration with C++ standard library coroutines

## Basic API Methods
#### Class Coroutine
- `Coroutine()` - Default constructor (creates empty coroutine)
- `Coroutine(Coroutine&& other_a)` - Move constructor
- `~Coroutine()` - Destructor (automatically destroys coroutine handle)
- `bool Resume()` - Resumes coroutine execution
- `bool Done() const` - Checks if coroutine has completed

## Example
#### cpp
```cpp
#include <CUtils/Coroutine.hpp>

// Coroutine function definition
CUtils::Coroutine ExampleCoroutine()
{
    co_await std::suspend_always{};
    // ... coroutine body
}

int main()
{
    // Create coroutine instance
    CUtils::Coroutine coro_ = ExampleCoroutine();
    
    // Resume coroutine execution
    while (coro_.Resume())
    {
        std::cout << "Coroutine suspended" << std::endl;
    }
    
    std::cout << "Coroutine finished: " << coro_.Done() << std::endl;
    return 0;
}
```

<a id="ru"></a>

# Coroutine Класс
Обертка над корутинами C++20 для управления асинхронными операциями.

## Возможности
- Управление жизненным циклом корутин
- Безопасная перемещающая семантика
- Перехват исключений
- Интеграция со стандартными корутинами C++

## Основные методы API
#### Класс Coroutine
- `Coroutine()` - Конструктор по умолчанию (создает пустую корутину)
- `Coroutine(Coroutine&& other_a)` - Перемещающий конструктор
- `~Coroutine()` - Деструктор (автоматически уничтожает обработчик корутины)
- `bool Resume()` - Возобновляет выполнение корутины
- `bool Done() const` - Проверяет завершение корутины

## Пример использования
#### cpp
```cpp
#include <CUtils/Coroutine.hpp>

// Определение функции сопрограммы
CUtils::Coroutine ExampleCoroutine()
{
    co_await std::suspend_always{};
    // ... Тело сопрограммы
}

int main()
{
    // Создать экземпляр сопрограммы
    CUtils::Coroutine coro_ = ExampleCoroutine();
    
    // Возобновить выполнение сопрограммы
    while (coro_.Resume())
    {
        std::cout << "Сопрограмма приостановлена" << std::endl;
    }
    
    std::cout << "Сопрограмма завершена: " << coro_.Done() << std::endl;
    return 0;
}
```