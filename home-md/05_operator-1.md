::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

Добавьте в класс `Fraction`:
- Перегрузку арифметических операторов (`+, -, *, /`)
- Перегрузку операторов сравнения (`==, !=, <, <=, >, >=`)
- Перегрузку унарного оператора отрицания (`-`)

---
### Пример использования класса
``` cpp
Fraction a(1, 2), b(3, 4);
{
	Fraction c = a + b;
	cout << c.toString() << endl; // 5/4
}
{
	Fraction c = a * b;
	cout << c.toString() << endl; // 3/8
}
{
	cout << (a < b) << endl; // true

	Fraction c = -a;
	cout << c.toString() << endl; // -1/2
}
```

---
### Тесты
``` cpp
// #define _CRT_SECURE_NO_WARNINGS
#include <assert.h>

#include "Fraction.cpp"

void Test1() {
	Fraction a, b;
	a.Init(1, 2);
	b.Init(3, 4);
	
	assert(a + b == Fraction(5, 4));
	assert(a - b == Fraction(-1, 4));
	assert(a * b == Fraction(3, 8));
	assert(a / b == Fraction(2, 3));
	
	assert(-b == Fraction(-3, 4));
	assert(a != b);
	assert(a < b);
	assert(!(a > b));

	assert(a == Fraction(1, 2));
	assert(b == Fraction(3, 4));
}

int main ()
{
	Test1();

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/e9b44f41728ca646)
:::
