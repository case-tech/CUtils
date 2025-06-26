[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Timer Class

High-precision timing utilities for performance measurement.

## Features
- Millisecond precision
- Start/Stop control
- Elapsed time retrieval
- Restart functionality
- Steady clock implementation
- Simple state management

## Basic API Methods
#### Class Timer
- `Timer()` - Constructor (initializes timer)
- `double GetMillisecondsElapsed()` - Gets elapsed time in ms
- `void Restart()` - Resets and starts timer
- `bool Stop()` - Stops timer (returns success)
- `bool Start()` - Starts timer (returns success)

## Example
#### cpp
```cpp
#include <CUtils/Timer.hpp>

int main()
{
    CUtils::Timer timer_;
    
    // Start timing
    timer_.Start();
    
    // Perform some operation
    for (int i_ = 0; i_ < 1000000; i_++) 
	{
        // Intensive computation...
    }
    
    // Stop timing
    timer_.Stop();
    
    // Get results
    double elapsed_ = timer_.GetMillisecondsElapsed();
    std::cout << "Operation took: " << elapsed_ << " ms" << std::endl;
    
    // Restart for new measurement
    timer_.Restart();
    // Another operation...
    
    return 0;
}
```

<a id="ru"></a>

# Timer Класс
Утилиты точного измерения времени для анализа производительности.

## Возможности
- Точность до миллисекунд
- Управление запуском/остановкой
- Получение прошедшего времени
- Функция перезапуска
- Реализация на steady clock
- Простое управление состоянием

## Основные методы API
#### Класс Timer
- `Timer()` - Конструктор (инициализирует таймер)
- `double GetMillisecondsElapsed()` - Получает прошедшее время в мс
- `void Restart()` - Сбрасывает и запускает таймер
- `bool Stop()` - Останавливает таймер (возвращает успех)
- `bool Start()` - Запускает таймер (возвращает успех)

## Пример использования
#### cpp
```cpp
#include <CUtils/Timer.hpp>

int main()
{
    CUtils::Timer timer_;
    
    // Старт таймера
    timer_.Start();
    
    // Выполните какую-нибудь операцию
    for (int i_ = 0; i_ < 1000000; i_++) 
	{
        // Интенсивные вычисления...
    }
    
    // Стоп таймер
    timer_.Stop();
    
    // Получение результатов
    double elapsed_ = timer_.GetMillisecondsElapsed();
    std::cout << "Операция заняла: " << elapsed_ << " ms" << std::endl;
    
    // Перезапустите для нового измерения
    timer_.Restart();
    // Еще одна операция...
    
    return 0;
}
```