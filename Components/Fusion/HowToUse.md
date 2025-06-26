[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Fusion Class

Advanced tuple manipulation utilities for modern C++.

## Features
- Tuple merging and concatenation
- Type-safe element access
- Runtime index-based element retrieval
- Tuple size calculation
- Tuple comparison
- Tuple printing
- Variant-based type handling

## Basic API Methods
#### Class Fusion
- `template <typename... Types> using Tuple = std::tuple<Types...>` - Tuple type alias
- `template <typename... T1, typename... T2> static auto Merge(const Tuple<T1...>&, const Tuple<T2...>&)` - Merges two tuples
- `template <size_t Index, typename... Types> static decltype(auto) Get(const Tuple<Types...>&)` - Gets element by compile-time index
- `template <typename T, typename... Types> static decltype(auto) GetByType(const Tuple<Types...>&)` - Gets element by type
- `template <typename... Types> static auto GetByIndex(const Tuple<Types...>&, size_t)` - Gets element by runtime index
- `template <typename... Types> static constexpr size_t Size(const Tuple<Types...>&)` - Gets tuple size
- `template <typename... T1, typename... T2> static bool AreEqual(const Tuple<T1...>&, const Tuple<T2...>&)` - Compares tuples
- `template <typename... Types> static void Print(const Tuple<Types...>&)` - Prints tuple contents

## Example
#### cpp
```cpp
#include <CUtils/Fusion.hpp>

int main()
{
    using namespace CUtils;
    
    // Create tuples
    Fusion::Tuple<int, std::string> t1_{42, "Hello"};
    Fusion::Tuple<double, char> t2_{3.14, 'A'};
    
    // Merge tuples
    auto merged_ = Fusion::Merge(t1_, t2_);
    
    // Access elements
    int n_ = Fusion::Get<0>(merged_);
    char c_ = Fusion::Get<3>(merged_);
    
    // Runtime access
    auto elem_ = Fusion::GetByIndex(merged_, 1); // std::variant containing "Hello"
    
    // Print tuple
    Fusion::Print(merged_); // Output: (42, Hello, 3.14, A)
    
    // Compare tuples
    if (Fusion::AreEqual(t1_, t1_)) 
    {
        std::cout << "Tuples are equal" << std::endl;
    }
    
    return 0;
}
```

<a id="ru"></a>

# Fusion Класс
Продвинутые утилиты для работы с кортежами в современном C++.

## Возможности
- Объединение кортежей
- Типобезопасный доступ к элементам
- Получение элементов по индексу в runtime
- Определение размера кортежа
- Сравнение кортежей
- Вывод содержимого кортежа
- Работа с вариантами (variant)

## Основные методы API
#### Класс Fusion
- `template <typename... Types> using Tuple = std::tuple<Types...>` - Псевдоним для кортежа
- `template <typename... T1, typename... T2> static auto Merge(const Tuple<T1...>&, const Tuple<T2...>&)` - Объединяет два кортежа
- `template <size_t Index, typename... Types> static decltype(auto) Get(const Tuple<Types...>&)` - Получает элемент по индексу (compile-time)
- `template <typename T, typename... Types> static decltype(auto) GetByType(const Tuple<Types...>&)` - Получает элемент по типу
- `template <typename... Types> static auto GetByIndex(const Tuple<Types...>&, size_t)` - Получает элемент по индексу (runtime)
- `template <typename... Types> static constexpr size_t Size(const Tuple<Types...>&)` - Возвращает размер кортежа
- `template <typename... T1, typename... T2> static bool AreEqual(const Tuple<T1...>&, const Tuple<T2...>&)` - Сравнивает кортежи
- `template <typename... Types> static void Print(const Tuple<Types...>&)` - Выводит содержимое кортежа

## Пример использования
#### cpp
```cpp
#include <CUtils/Fusion.hpp>

int main()
{
    using namespace CUtils;
    
    // Создавать кортежи
    Fusion::Tuple<int, std::string> t1_{42, "Hello"};
    Fusion::Tuple<double, char> t2_{3.14, 'A'};
    
    // Объединить кортежи
    auto merged_ = Fusion::Merge(t1_, t2_);
    
    // Доступ к элементам
    int n_ = Fusion::Get<0>(merged_);
    char c_ = Fusion::Get<3>(merged_);
    
    // Доступ к среде выполнения
    auto elem_ = Fusion::GetByIndex(merged_, 1); // std::variant containing "Hello"
    
    // Напечатать кортеж
    Fusion::Print(merged_); // Output: (42, Hello, 3.14, A)
    
    // Сравнить кортежи
    if (Fusion::AreEqual(t1_, t1_)) 
    {
        std::cout << "Tuples are equal" << std::endl;
    }
    
    return 0;
}
```