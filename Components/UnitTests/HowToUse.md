[English](#en) | [Русский](#ru)

---

<a id="en"></a>
# UnitTests Class

Minimalist unit testing framework for C++ projects.

## Features
- Assertion macros for common checks
- Test case registration
- Test execution and reporting
- Exception testing
- Case-insensitive string comparisons
- Simple test organization
- Automatic test discovery

## Basic API Macros
#### Test Registration
- `UTEST(test_case_name, test_name)` - Defines a test case

#### Assertions
- `ASSERT_TRUE(condition)` - Fails if condition is false
- `ASSERT_FALSE(condition)` - Fails if condition is true
- `ASSERT_EQ(expected, actual)` - Fails if values not equal
- `ASSERT_NE(val1, val2)` - Fails if values equal
- `ASSERT_LT(val1, val2)` - Fails if val1 >= val2
- `ASSERT_LE(val1, val2)` - Fails if val1 > val2
- `ASSERT_GT(val1, val2)` - Fails if val1 <= val2
- `ASSERT_GE(val1, val2)` - Fails if val1 < val2
- `ASSERT_STREQ(expected_str, actual_str)` - Fails if C-strings not equal
- `ASSERT_STRNE(str1, str2)` - Fails if C-strings equal
- `ASSERT_STRCASEEQ(expected_str, actual_str)` - Case-insensitive string comparison
- `ASSERT_STRCASENE(str1, str2)` - Case-insensitive string inequality
- `ASSERT_THROW(statement, exception_type)` - Fails if no exception thrown
- `ASSERT_NO_THROW(statement)` - Fails if exception thrown

#### Test Control
- `SUCCEED()` - Explicitly mark test as successful
- `FAIL()` - Explicitly fail test
- `RUN_ALL_TESTS()` - Executes all registered tests

## Example
#### cpp
```cpp
#include <CUtils/UnitTests.hpp>

UTEST(MathTests, Addition) 
{
    int result_ = 2 + 2;
    ASSERT_EQ(4, result_);
}

UTEST(MathTests, Division) 
{
    ASSERT_THROW(10 / 0, std::exception);
}

UTEST(StringTests, CaseInsensitive) 
{
    ASSERT_STRCASEEQ("HELLO", "hello");
}

int main() 
{
    return RUN_ALL_TESTS();
}
```

<a id="ru"></a>

# UnitTests Класс
Минималистичный фреймворк для модульного тестирования C++ проектов.

## Возможности
- Макросы проверок (assertions)
- Регистрация тестовых случаев
- Выполнение тестов и отчетность
- Тестирование исключений
- Регистронезависимые сравнения строк
- Простая организация тестов
- Автоматическое обнаружение тестов

## Основные макросы API
#### Регистрация тестов
- `UTEST(test_case_name, test_name)` - Определяет тестовый случай

#### Проверки
- `ASSERT_TRUE(condition)` - Ошибка если условие ложно
- `ASSERT_FALSE(condition)` - Ошибка если условие истинно
- `ASSERT_EQ(expected, actual)` - Ошибка если значения не равны
- `ASSERT_NE(val1, val2)` - Ошибка если значения равны
- `ASSERT_LT(val1, val2)` - Ошибка если val1 >= val2
- `ASSERT_LE(val1, val2)` - Ошибка если val1 > val2
- `ASSERT_GT(val1, val2)` - Ошибка если val1 <= val2
- `ASSERT_GE(val1, val2)` - Ошибка если val1 < val2
- `ASSERT_STREQ(expected_str, actual_str)` - Ошибка если C-строки не равны
- `ASSERT_STRNE(str1, str2)` - Ошибка если C-строки равны
- `ASSERT_STRCASEEQ(expected_str, actual_str)` - Регистронезависимое сравнение
- `ASSERT_STRCASENE(str1, str2)` - Регистронезависимое неравенство
- `ASSERT_THROW(statement, exception_type)` - Ошибка если исключение не брошено
- `ASSERT_NO_THROW(statement)` - Ошибка если брошено исключение

#### Управление тестами
- `SUCCEED()` - Явно отмечает тест как успешный
- `FAIL()` - Явно проваливает тест
- `RUN_ALL_TESTS()` - Выполняет все зарегистрированные тесты

## Пример использования
#### cpp
```cpp
#include <CUtils/UnitTests.hpp>

UTEST(MathTests, Addition) 
{
    int result_ = 2 + 2;
    ASSERT_EQ(4, result_);
}

UTEST(MathTests, Division) 
{
    ASSERT_THROW(10 / 0, std::exception);
}

UTEST(StringTests, CaseInsensitive) 
{
    ASSERT_STRCASEEQ("HELLO", "hello");
}

int main() 
{
    return RUN_ALL_TESTS();
}
```