::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ: Введение

В файле `Fraction.cpp` реализуйте класс `Fraction` (дробь). Необходимо хранить в качестве полей (переменных-членов класса) числитель и знаменатель.
Реализуйте методы (функции-члены класса) : 
- `Init` - для ввода данных в поля
- `ToString` - возвращает дробь в виде строки
- `GetNumerator` - метод, возвращающий числитель
- `GetDenominator` - метод, возвращающий знаменатель
- и выполнения арифметических операций:
	- `Sum` - сложение
	- `Sub` - вычитание
	- `Mult` - умножение
	- `Div` - деление

Также вам будет необходимо сокращать дробь, при необходимости.
Поля должны быть приватными.

---
### Пример использования класса в двух вариантах (на выбор)
``` cpp
#if LVL_EASY /// вариант на выбор (1,0):
	Fraction a, b;
	a.Init(1, 2);
	b.Init(3, 4);
	double x = a.Sum(b);
	cout << a.ToString() << endl; // 1/2
	cout << b.ToString() << endl; // 3/4
	cout << x << endl;// 1.25
#else
	Fraction a, b;
	a.Init(1, 2);
	b.Init(3, 4);
	Fraction c = a.Sum(b);
	cout << a.ToString() << endl; // 1/2
	cout << b.ToString() << endl; // 3/4
	cout << c.ToString() << endl; // 5/4
#endif
```

---
### Тесты
``` cpp
#include <assert.h>
#include <iostream>
using namespace std;

#include "Fraction.cpp"

#define LVL_EASY 1 /// выберите вариант (1,0):

bool operator==(Fraction a, Fraction b) {
	return a.GetNumerator() == b.GetNumerator() && a.GetDenominator() == b.GetDenominator();
}
bool operator!=(Fraction a, Fraction b) {
	return !(a == b);
}
Fraction CreateFraction(int numerator, int denominator) {
	Fraction a;
	a.Init(numerator, denominator);
	return a;
}
void Test1() {
	Fraction a, b;
	a.Init(1, 2);
	b.Init(3, 4);
	
#if LVL_EASY
	assert((a.Sum(b) == 1.25));
	assert((a.Sub(b) == -0.25));
	assert((a.Mult(b) == 3.0/8));
	assert((a.Div(b) - 2.0/3) < 0.0000001);
#else
	assert((a.Sum(b) == CreateFraction(5, 4)));
	assert((a.Sub(b) == CreateFraction(-1, 4)));
	assert((a.Mult(b) == CreateFraction(3, 8)));
	assert((a.Div(b) == CreateFraction(2, 3)));
#endif

	assert((a == CreateFraction(1, 2)));
	assert((b == CreateFraction(3, 4)));
}

int main() 
{
	Test1();

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/cb4c58bad01b0f6e)

:::
