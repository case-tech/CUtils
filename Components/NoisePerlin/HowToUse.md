[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# NoisePerlin Class

Perlin noise generator for procedural content creation.

## Features
- 2D coherent noise generation
- Seeded randomization
- Smooth interpolation
- Normalized output [0.0, 1.0]
- Classic Perlin noise implementation

## Basic API Methods
#### Class NoisePerlin
- `NoisePerlin(unsigned int seed_a = 0)` - Constructor with optional seed
- `double Noise(double x_a, double y_a) const` - Generates noise value at coordinates

## Example
#### cpp
```cpp
#include <CUtils/NoisePerlin.hpp>

int main()
{
    // Create generator with seed
    CUtils::NoisePerlin noise_(12345);
    
    // Generate terrain heightmap
    const int width_ = 100;
    const int height_ = 100;
    double scale_ = 0.1;
    
    for (int y_ = 0; y_ < height_; ++y_) 
	{
        for (int x_ = 0; x_ < width_; ++x_) 
		{
            // Sample noise with coordinates
            double value_ = noise_.Noise(x_ * scale_, y_ * scale_);
            
            // Convert to height (0-255)
            int height_value_ = static_cast<int>(value_ * 255);
        }
    }
    
    return 0;
}
```

<a id="ru"></a>

# NoisePerlin Класс
Генератор шума Перлина для процедурной генерации контента.

## Возможности
- Генерация 2D когерентного шума
- Инициализация сидом (seed)
- Плавная интерполяция
- Нормализованный вывод [0.0, 1.0]
- Классическая реализация шума Перлина

## Основные методы API
#### Класс NoisePerlin
- `NoisePerlin(unsigned int seed_a = 0)` - Конструктор с опциональным сидом
- `double Noise(double x_a, double y_a) const` - Генерирует значение шума в координатах

## Пример использования
#### cpp
```cpp
#include <CUtils/NoisePerlin.hpp>

int main()
{
    // Создать генератор с сидом
    CUtils::NoisePerlin noise_(12345);
    
    // Генерация местности по heightmap
    const int width_ = 100;
    const int height_ = 100;
    double scale_ = 0.1;
    
    for (int y_ = 0; y_ < height_; ++y_) 
	{
        for (int x_ = 0; x_ < width_; ++x_) 
		{
            // Выборка шума с координатами
            double value_ = noise_.Noise(x_ * scale_, y_ * scale_);
            
            // Преобразовать в высоту (0-255)
            int height_value_ = static_cast<int>(value_ * 255);
        }
    }
    
    return 0;
}
```