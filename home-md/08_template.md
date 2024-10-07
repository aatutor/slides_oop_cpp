::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

- Объявить класс `Array` для хранения динамического массива шаблонного типа. Описать:
	- конструктор, инициализирующий массив `списком инициализации`.
	- конструктор, инициализирующий массив количеством и значением по умолчанию.
	- остальные необходимые конструкторы
	- деструктор
	- перегрузку `+` - конкатенация, слияние двух массивов
	- перегрузку `<<` - вывод в поток
	- метод `Len` - размер массива
	- перегрузка `[]` - доступ по индексу

---
### Пример использования класса
``` cpp
Array<int> alfa({1, 2, 3});
Array<int> beta({4, 5});
Array<int> gama(3, 9);	// {9,9,9}
beta[1] = 6;
cout << (alfa + beta + gama) << endl; // 1 2 3 4 6 9 9 9
```

---
### Тесты
``` cpp
#include <assert.h>
#include <iostream>
#include <sstream>
using namespace std;

#include "Array.cpp"

void TestInt() {
	Array<int> arr({1, 2, 3}), oth({4, 5});
	assert(arr.Len() == 3);
	assert(arr[0] == 1);
	assert(arr[1] == 2);
	assert(arr[2] == 3);
	stringstream ss;
	ss << arr;
	assert(std::string{ss.str()} == "1 2 3 ");
	arr[0] = 10;
	assert(arr[0] == 10);
	ss.str("");
	ss << arr;
	assert(std::string{ss.str()} == "10 2 3 ");
	ss.str("");
	ss << (arr + oth);
	assert( std::string{ss.str()} == "10 2 3 4 5 ");
}
void TestDouble() {
	Array<double> arr({1, 2, 3}), oth({4, 5});
	assert(arr.Len() == 3);
	assert(arr[0] == 1);
	assert(arr[1] == 2);
	assert(arr[2] == 3);
	stringstream ss;
	ss << arr;
	assert(std::string{ss.str()} == "1 2 3 ");
	arr[0] = 10;
	assert(arr[0] == 10);
	ss.str("");
	ss << arr;
	assert(std::string{ss.str()} == "10 2 3 ");
	ss.str("");
	ss << (arr + oth);
	assert( std::string{ss.str()} == "10 2 3 4 5 ");
}

int main ()
{
	TestInt();
	cout << "Int done\n";
	TestDouble();
	cout << "Double done\n";
	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/0bce2e124479a5bd)
:::
