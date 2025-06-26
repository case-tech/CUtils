[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Multithread Class

Thread management utilities for parallel task execution.

## Features
- Task queue management
- Exception-safe thread execution
- Batch thread creation
- Flexible task joining options
- Graceful thread cancellation
- Automatic resource cleanup
- Task binding with arguments

## Basic API Methods
#### Class Multithread
- `template<typename Callable, typename... Args> void AddTask(Callable&& func_a, Args&&... args_a)` - Adds task to queue
- `void Run()` - Starts all tasks in separate threads
- `void JoinAll()` - Waits for all threads to complete
- `void JoinOne(std::thread& t_a)` - Waits for specific thread
- `void CancelAll()` - Cancels all threads without waiting

## Example
#### cpp
```cpp
#include <CUtils/Multithread.hpp>

void Task1(int param_a) 
{
    std::cout << "Task1: " << param_a << std::endl;
}

void Task2(const std::string& text_a) 
{
    std::cout << "Task2: " << text_a << std::endl;
}

int main()
{
    CUtils::Multithread manager_;
    
    // Add tasks with parameters
    manager_.AddTask(Task1, 42);
    manager_.AddTask(Task2, "Hello Thread");
    manager_.AddTask([]() 
	{
        std::cout << "Lambda task" << std::endl;
    });
    
    // Run all tasks in parallel
    manager_.Run();
    
    // Wait for all tasks to complete
    manager_.JoinAll();
    
    return 0;
}
```

<a id="ru"></a>

# Multithread Класс
Утилиты для управления потоками и параллельного выполнения задач.

## Возможности
- Управление очередью задач
- Безопасное выполнение потоков с обработкой исключений
- Пакетное создание потоков
- Гибкие варианты ожидания потоков
- Корректная отмена потоков
- Автоматическое освобождение ресурсов
- Привязка аргументов к задачам

## Основные методы API
#### Класс Multithread
- `template<typename Callable, typename... Args> void AddTask(Callable&& func_a, Args&&... args_a)` - Добавляет задачу в очередь
- `void Run()` - Запускает все задачи в отдельных потоках
- `void JoinAll()` - Ожидает завершения всех потоков
- `void JoinOne(std::thread& t_a)` - Ожидает завершения конкретного потока
- `void CancelAll()` - Отменяет все потоки без ожидания

## Пример использования
#### cpp
```cpp
#include <CUtils/Multithread.hpp>

void Task1(int param_a) 
{
    std::cout << "Задача1: " << param_a << std::endl;
}

void Task2(const std::string& text_a) 
{
    std::cout << "Задача2: " << text_a << std::endl;
}

int main()
{
    CUtils::Multithread manager_;
    
    // Добавить задачи с параметрами
    manager_.AddTask(Task1, 42);
    manager_.AddTask(Task2, "Hello Thread");
    manager_.AddTask([]() 
	{
        std::cout << "Лямбда задача" << std::endl;
    });
    
    // Запустить все задачи в разных потоках
    manager_.Run();
    
    // Дождаться завершения всех заданий
    manager_.JoinAll();
    
    return 0;
}
```