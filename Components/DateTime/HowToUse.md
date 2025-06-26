[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# DateTime Class

Cross-platform date and time manipulation utilities.

## Features
- Current date/time retrieval
- Custom formatting (strftime compatible)
- Time storage and manipulation
- Comparison operators
- `Windows/Linux/macOS` support

## Basic API Methods
#### Class DateTime
- `DateTime()` - Constructor with current system time
- `DateTime(time_t time_a)` - Constructor with custom time
- `std::string GetCurrentDateTime() const` - Returns "YYYY-MM-DD HH:MM:SS"
- `std::string GetCurrentDate() const` - Returns "YYYY-MM-DD"
- `std::string GetCurrentTime() const` - Returns "HH:MM:SS"
- `std::string Format(const std::string& format_a) const` - Custom time formatting
- `void SetTime(time_t time_a)` - Set custom time value
- `time_t GetTime() const` - Get raw time value
- Comparison operators (`==`, `!=`, `<`, `>`, `<=`, `>=`)

## Example
#### cpp
```cpp
#include <CUtils/DateTime.hpp>

int main()
{
    // Create with current time
    CUtils::DateTime now_;
    
    // Format examples
    std::cout << "Full datetime: " << now_.GetCurrentDateTime() << std::endl;
    std::cout << "Custom format: " << now_.Format("%A, %B %d") << std::endl;
    
    // Time manipulation
    time_t yesterday_ = now_.GetTime() - 86400;  // 86400 seconds = 1 day
    CUtils::DateTime past_(yesterday_);
    
    // Comparison
    if (past_ < now_) 
    {
        std::cout << "Yesterday was earlier than today" << std::endl;
    }
    
    return 0;
}
```

<a id="ru"></a>
# DateTime Класс
Кросс-платформенные утилиты для работы с датой и временем.

## Возможности
- Получение текущей даты/времени
- Произвольное форматирование (совместимо с strftime)
- Хранение и манипуляция временем
- Операторы сравнения
- Поддержка `Windows/Linux/macOS`

## Основные методы API
#### Класс DateTime
- `DateTime()` - Конструктор с текущим системным временем
- `DateTime(time_t time_a)` - Конструктор с пользовательским временем
- `std::string GetCurrentDateTime() const` - Возвращает "ГГГГ-ММ-ДД ЧЧ:ММ:СС"
- `std::string GetCurrentDate() const` - Возвращает "ГГГГ-ММ-ДД"
- `std::string GetCurrentTime() const` - Возвращает "ЧЧ:ММ:СС"
- `std::string Format(const std::string& format_a) const` - Произвольное форматирование
- `void SetTime(time_t time_a)` - Установка пользовательского времени
- `time_t GetTime() const` - Получение времени в сыром виде
- Операторы сравнения `(==, !=, <, >, <=, >=)`

## Пример использования
#### cpp
```cpp
#include <CUtils/DateTime.hpp>

int main()
{
    // Создавать с учетом текущего времени
    CUtils::DateTime now_;
    
    // Примеры форматирования
    std::cout << "Полная дата и время: " << now_.GetCurrentDateTime() << std::endl;
    std::cout << "Пользовательский формат: " << now_.Format("%A, %B %d") << std::endl;
    
    // Манипулирование временем
    time_t yesterday_ = now_.GetTime() - 86400;  // 86400 секунд = 1 день
    CUtils::DateTime past_(yesterday_);
    
	// Сравнение
    if (past_ < now_) 
    {
        std::cout << "Вчера было раньше, чем сегодня" << std::endl;
    }
    
    return 0;
}
```