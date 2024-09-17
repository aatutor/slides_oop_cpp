::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ: namespace

В файле `solve.h` описать две функции `Convert`, для конвертации даты из трех чисел (день, месяц, год) в строку (`string`), в двух __пространствах__:
- `Slashed` - в формат "1/1/2000"
- `Lexical` - в формат "1 January 2000"
	- Для получения списка месяцев нужно воспользоваться файлом `solve.h`

> Если при запуске исполняемого файла вы видите запись `Assertion failed: ...` - значит какой-то тест не был пройден.

---
### Пример использования класса
``` cpp
cout << Slashed::Convert(1, 1, 2000) << endl; // 1/1/2000

cout << Lexical::Convert(1, 1, 2000) << endl; // 1 January 2000
```

- project/
	- calendar.h
	- <u>solve.h</u> <- (ваше решение)
	- main.cpp
<!-- <u>calendar.h:</u> -->
``` cpp
/// calendar.h
#include <string>

namespace Calendar {
	std::string months[12] = {"January", "February", "March", "April", "May", 
			"June", "July", "August", "September", "October", "November", "December"};
}
```
---
### Тесты для проверки работоспособности
``` cpp
/// main.cpp
#include <iostream>
#include <string>
#include <assert.h>

#include "solve.h" // <- ваше решение

std::string GetDashedDate(int day, int month, int year) {
	std::string result = Slashed::Convert(day, month, year);
	std::cout << result << std::endl;
	return result;
}
std::string GetLexicalDate(int day, int month, int year) {
	std::string result = Lexical::Convert(day, month, year);
	std::cout << result << std::endl;
	return result;
}

void TestSlashed() {
	assert(GetDashedDate(1, 1, 2000) == "1/1/2000");
	assert(GetDashedDate(31, 12, 1999) == "31/12/1999");
	assert(GetDashedDate(15, 9, 2020) == "15/9/2020");
}
void TestLexical() {
	assert(GetLexicalDate(1, 1, 2000) == "1 January 2000");
	assert(GetLexicalDate(31, 12, 1999) == "31 December 1999");
	assert(GetLexicalDate(15, 9, 2020) == "15 September 2020");
}

int main ()
{
	TestSlashed();
	TestLexical();

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/19c52b546ed83308)

:::
