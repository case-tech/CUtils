[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Notification Class

Cross-platform console notification system with colored output.

## Features
- Color-coded message types
- Windows/Linux/macOS support
- Error/Warning/Info notifications
- Automatic color resetting
- Simple unified interface

## Notification Types
- `TYPE_ERROR`: Critical issues (red)
- `TYPE_WARNING`: Potential problems (yellow)
- `TYPE_INFO`: General information (cyan/white)

## Basic API Methods
#### Class Notification
- `static void Notify(NotificationType type_a, const std::string& message_a)` - Displays colored notification

## Example
#### cpp
```cpp
#include <CUtils/Notification.hpp>

int main()
{
    // Display different notification types
    CUtils::Notification::Notify(
        CUtils::Notification::TYPE_INFO,
        "Application started successfully"
    );
    
    CUtils::Notification::Notify(
        CUtils::Notification::TYPE_WARNING,
        "Low memory detected"
    );
    
    CUtils::Notification::Notify(
        CUtils::Notification::TYPE_ERROR,
        "Failed to load critical resource"
    );
    
    return 0;
}
```

<a id="ru"></a>

# Notification Класс
Кросс-платформенная система уведомлений для консоли с цветным выводом.

## Возможности
- Цветовая индикация типов сообщений
- Поддержка Windows/Linux/macOS
- Ошибки/Предупреждения/Информация
- Автоматический сброс цвета
- Простой унифицированный интерфейс

## Типы уведомлений
- `TYPE_ERROR`: Критические ошибки (красный)
- `TYPE_WARNING`: Потенциальные проблемы (желтый)
- `TYPE_INFO`: Общая информация (голубой/белый)

## Основные методы API
#### Класс Notification
- `static void Notify(NotificationType type_a, const std::string& message_a)` - Выводит цветное уведомление

## Пример использования
#### cpp
```cpp
#include <CUtils/Notification.hpp>

int main()
{
    // Отображение различных типов уведомлений
    CUtils::Notification::Notify(
        CUtils::Notification::TYPE_INFO,
        "Application started successfully"
    );
    
    CUtils::Notification::Notify(
        CUtils::Notification::TYPE_WARNING,
        "Low memory detected"
    );
    
    CUtils::Notification::Notify(
        CUtils::Notification::TYPE_ERROR,
        "Failed to load critical resource"
    );
    
    return 0;
}
```