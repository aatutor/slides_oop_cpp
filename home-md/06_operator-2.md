::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

В существующий класс `Fraction` добавить перегрузку операторов для выполнения операций:
- `++(дробь)` и `(дробь)++` - увеличение числа на 1
- `cout <<` - вывод дроби в консоль
- `cin >>` - считывание значений дроби из консоли
<!-- - оператор __копирования__ и __перемещения__ -->

---
### Пример использования класса
``` cpp
Fraction a(1, 2), b(3, 4);
cout << ++a << endl	// 3/2
     << b++ << endl; // 3/4
cin >> a;// 2/5
cout << a << endl	// 2/5
     << b << endl; // 7/4
```

---
### Тесты
``` cpp
#include <assert.h>
#include <iostream>
#include <sstream>
using namespace std;

#include "Fraction.cpp"

void TestInc() {
	Fraction a(1, 2), b(3, 2);
	{
		Fraction f(1, 2);
		assert(++f == b);
		assert(f == b);
	}
	{
		Fraction f(1, 2);
		assert(f++ == a);
		assert(f == b);
	}
}
void TestOstream() {
	ostringstream s;
	s << Fraction(1, 2);
	assert(s.str() == "1/2");
}
void TestIstream() {
	istringstream s("1 2");
	Fraction f;
	s >> f;
	assert(f == Fraction(1, 2));
}

int main ()
{
	TestInc();
	TestOstream();
	TestIstream();

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/da1a3ddfdb494f19)
:::
