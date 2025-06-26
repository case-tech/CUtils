[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# Random Class

Advanced random number generation utilities with multiple distributions.

## Features
- Uniform integer distribution
- Uniform real distribution
- Normal (Gaussian) distribution
- Binomial distribution
- Bernoulli distribution
- Poisson distribution
- Automatic seed initialization
- Thread-safe usage patterns
- Modern C++ <random> implementation

## Basic API Methods
#### Class Random
- `Random()` - Constructor with time-based seed initialization
- `int RandomInt(int min_a, int max_a)` - Uniform integer in range [min, max]
- `double RandomDouble(double min_a, double max_a)` - Uniform real in range [min, max]
- `double NormalDouble(double mean_a, double stddev_a)` - Normal distribution
- `int BinomialInt(int t_a, double p_a)` - Binomial distribution
- `bool BernoulliBool(double p_a)` - Bernoulli trial
- `int PoissonInt(double mean_a)` - Poisson distribution

## Example
#### cpp
```cpp
#include <CUtils/Random.hpp>

int main()
{
    CUtils::Random rng_;
    
    // Basic random numbers
    int dice_ = rng_.RandomInt(1, 6);
    double percent_ = rng_.RandomDouble(0.0, 100.0);
    
    // Statistical distributions
    double height_ = rng_.NormalDouble(175.0, 10.0); // Mean=175, SD=10
    bool success_ = rng_.BernoulliBool(0.3); // 30% success chance
    int events_ = rng_.PoissonInt(5.0); // Mean events=5
    
    int damage_ = rng_.BinomialInt(10, 0.8); // 10 trials, 80% success
    
    return 0;
}
```

<a id="ru"></a>

# Random Класс
Продвинутые утилиты генерации случайных чисел с различными распределениями.

## Возможности
- Равномерное распределение целых чисел
- Равномерное распределение вещественных чисел
- Нормальное (Гауссово) распределение
- Биномиальное распределение
- Распределение Бернулли
- Распределение Пуассона
- Автоматическая инициализация сида
- Потокобезопасные шаблоны использования
- Современная реализация на базе <random>

## Основные методы API
#### Класс Random
- `Random()` - Конструктор с инициализацией сида по времени
- `int RandomInt(int min_a, int max_a)` - Целое число в диапазоне [min, max]
- `double RandomDouble(double min_a, double max_a)` - Вещественное число в [min, max]
- `double NormalDouble(double mean_a, double stddev_a)` - Нормальное распределение
- `int BinomialInt(int t_a, double p_a)` - Биномиальное распределение
- `bool BernoulliBool(double p_a)` - Испытание Бернулли
- `int PoissonInt(double mean_a)` - Распределение Пуассона

## Пример использования
#### cpp
```cpp
#include <CUtils/Random.hpp>

int main()
{
    CUtils::Random rng_;
    
    // Основные случайные числа
    int dice_ = rng_.RandomInt(1, 6);
    double percent_ = rng_.RandomDouble(0.0, 100.0);
    
    // Статистические распределения
    double height_ = rng_.NormalDouble(175.0, 10.0); // Mean=175, SD=10
    bool success_ = rng_.BernoulliBool(0.3); // 30% success chance
    int events_ = rng_.PoissonInt(5.0); // Mean events=5
    
    int damage_ = rng_.BinomialInt(10, 0.8); // 10 trials, 80% success
    
    return 0;
}
```