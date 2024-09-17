::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ: Статичность, константность

1. Дополните класс `Fraction` так, чтобы шел подсчет количества созданных объектов (дробей).
1. Добавьте метод `GetCount`, который возвращает это количество
1. Добавьте параметр `const` ко всем методам и аргументам, к которым возможно.

---
Пример использования класса:
``` cpp
const Fraction f{1, 3};
cout << f.ToString() << endl; // 1/3

cout << Fraction::GetCount() << endl; // 1

Fraction f1, f2;
cout << f.GetCount() << endl; // 3

Fraction* pf3 = new Fraction();
cout << pf3->GetCount() << endl; // 4

delete pf3;
cout << Fraction::GetCount() << endl; // 3
```

---
### Тесты
``` cpp
// #define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <iostream>
using namespace std;

#include "Fraction.cpp"

void TestCount() {
	assert(Fraction::GetCount() == 0);
	Fraction f1;
	assert(f1.GetCount() == 1);
	Fraction f2(1, 1);
	assert(f1.GetCount() == 2);
	Fraction* pf3 = new Fraction(1, 2);
	assert(pf3->GetCount() == 3);
	delete pf3;
	assert(Fraction::GetCount() == 2);
}
void TestConst() {
	assert(Fraction::GetCount() == 0);
	const Fraction f1;
	assert(f1.GetCount() == 1);
	const Fraction f2(1, 1);
	assert(f1.GetCount() == 2);
	const Fraction* pf3 = new Fraction(1, 2);
	cout << f2.ToString() << endl;
	f1.Sum(f2);
	f2.Sub(f2);
	f2.Mult(f2);
	f2.Div(f2);
	f1.GetNumerator();
	f1.GetDenominator();
}

int main ()
{
	TestCount();
	TestConst();

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)


<small>[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)</small>
<!-- .element: hidden="hidden" -->

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/29757b0607795d55)

:::
