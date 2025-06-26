[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# SystemConfiguration Class

Cross-platform system information retrieval utilities.

## Features
- OS name and version detection
- CPU architecture and model identification
- Physical memory reporting
- Disk space information
- Windows/Linux/macOS support
- No external dependencies

## Basic API Methods
#### Class SystemConfiguration
- `static std::string GetOSName()` - Returns OS name
- `static std::string GetOSVersion()` - Returns OS version
- `static std::string GetCPUInfo()` - Returns CPU information
- `static std::string GetMemoryInfo()` - Returns memory information
- `static std::string GetDiskInfo()` - Returns disk space information

## Example
#### cpp
```cpp
#include <CUtils/SystemConfiguration.hpp>

int main()
{
    std::cout << "Operating System: " 
              << CUtils::SystemConfiguration::GetOSName() 
              << " " 
              << CUtils::SystemConfiguration::GetOSVersion() 
              << std::endl;
              
    std::cout << "Processor: " 
              << CUtils::SystemConfiguration::GetCPUInfo() 
              << std::endl;
              
    std::cout << "Memory: " 
              << CUtils::SystemConfiguration::GetMemoryInfo() 
              << std::endl;
              
    std::cout << "Disk Space: " 
              << CUtils::SystemConfiguration::GetDiskInfo() 
              << std::endl;
              
    return 0;
}
```

<a id="ru"></a>

# SystemConfiguration Класс
Кросс-платформенные утилиты для получения информации о системе.

## Возможности
- Определение имени и версии ОС
- Идентификация архитектуры и модели процессора
- Получение информации об оперативной памяти
- Получение информации о дисковом пространстве
- Поддержка Windows/Linux/macOS
- Отсутствие внешних зависимостей

## Основные методы API
#### Класс SystemConfiguration
- `static std::string GetOSName()` - Возвращает имя ОС
- `static std::string GetOSVersion()` - Возвращает версию ОС
- `static std::string GetCPUInfo()` - Возвращает информацию о процессоре
- `static std::string GetMemoryInfo()` - Возвращает информацию о памяти
- `static std::string GetDiskInfo()` - Возвращает информацию о дисковом пространстве

## Пример использования
#### cpp
```cpp
#include <CUtils/SystemConfiguration.hpp>

int main()
{
    std::cout << "Операционная система: " 
              << CUtils::SystemConfiguration::GetOSName() 
              << " " 
              << CUtils::SystemConfiguration::GetOSVersion() 
              << std::endl;
              
    std::cout << "Процессор: " 
              << CUtils::SystemConfiguration::GetCPUInfo() 
              << std::endl;
              
    std::cout << "Память: " 
              << CUtils::SystemConfiguration::GetMemoryInfo() 
              << std::endl;
              
    std::cout << "Дисковое пространство: " 
              << CUtils::SystemConfiguration::GetDiskInfo() 
              << std::endl;
              
    return 0;
}
```