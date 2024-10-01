::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

Дополните класс `String`, добавив перегрузки:
- `оператор [ind]` для доступа к символу по его индексу
- `оператор (count)` для получения подстроки в указанном количестве символов начиная с начала строки
- `оператор (ind, count)` для получения подстроки - начиная с индекса
- приведение к типу `int` - возвращает длину строки
- приведение к типу `bool` - проверка на пустоту строки 
- запретить __неявное приведение__ к типам

Также добавьте остальные необходимые перегрузки.

<!-- Реализуйте класс "Контакт", с именем, адресом и телефоном.
Реализуйте класс "Телефонная книга", со списком контактов.
Объявите все необходимые конструкторы и методы для работы с телефонной книгой и контктами.
Добавьте необходимые перегрузки операторов для более удобного взаимодействия. -->


---
### Пример использования класса
``` cpp []
String s("Hello world");
s[0] = 'M';
String sub = s(5);	
cout << sub << endl; // Mello

sub = s(6, 5);
cout << sub << endl; // world

int count = (int)s;
cout << count << endl; // 11

String emp;
if ((bool)emp)
	cout << emp << endl;
else
	cout << "String is empty\n";
```

---
### Тесты
``` cpp
#include <assert.h>
#include <iostream>

#include "String.cpp"

void TestBrackets() {
	String t("testing");
	assert(t[0] == 't');
	assert(t[2] == 's');
	assert(t[5] == 'n');

	t[0] = 'T';
	assert(t[0] == 'T');

	assert(t(4).GetStr() == "Test"s);
	assert(t(4, 3).GetStr() == "ing"s);
}
void TestCast() {
	String t("testing"), s("");

	assert((int)t == 7);
	assert((int)s == 0);

	assert((bool)t);
	assert(!(bool)s);
}

int main ()
{
	TestBrackets();
	TestCast();

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/64a8fa265823b385)
:::
