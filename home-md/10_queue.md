::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ
- Реализовать шаблонный класс `Printer` с методами:
	- `Add` - добавляет объекты в очередь печати (один или несколько)
	- `Print` - возвращает строку из `n` объектов, начиная с первых добавленных. Если `n` не указанно, то возвращает всю очередь
	- `Len` - возвращает количество объектов в очереди
	- `IsEmpty` - указывает, пуста ли очередь	
- *Примечание: для инициализации множества объектов можно использовать класс `std::initializer_list`*

---
### ВАЖНО!
- В классе `Printer` используйте написанный вами класс `Queue` (или `std::queue`) для выполнения задания.

- <u>**ВАЖНО!**</u> Класс `Queue` должен оставаться <u>универсальным</u> - не нужно править его под данную задачу, его нужно лишь <u>ИСПОЛЬЗОВАТЬ!</u>
	- Если вы используете `std::queue` из библиотеки, то это условие выполнится автоматически.

---
### Пример использования класса
``` cpp
Printer<int> p;
p.Add({1, 2, 3, 4, 5, 6});
cout << "Added = " << p.Len() << endl; // 6

cout << "Print: " << p.Print(3) << endl;// 1 2 3
cout << "After = " << p.Len() << endl; // 3

cout << "Print: " << p.Print(2) << endl;// 4 5

p.Add({7, 8, 9});
cout << "Print: " << p.Print() << endl;// 6 7 8 9

p.Add(10);
cout << "Print: " << p.Print() << endl; // 10
cout << "IsEmpty: " << p.IsEmpty() << endl; // 1
```

---
### Тесты
Придется поискать шаблонное решение
``` cpp
#include <assert.h>
#include <iostream>

#include "solve.h"

void TestInt() {
	Printer<int> p;
	assert(p.IsEmpty());
	p.Add(0);
	assert(!p.IsEmpty());
	assert(p.Len() == 1);
	assert(p.Print() == "0 ");
	p.Add({1, 2, 3});
	assert(p.Len() == 3);
	assert(p.Print(1) == "1 ");
	assert(p.Print() == "2 3 ");
}
void TestChar() {
	Printer<char> p;
	assert(p.IsEmpty());
	p.Add('a');
	assert(!p.IsEmpty());
	assert(p.Len() == 1);
	assert(p.Print() == "a ");
	p.Add({'b', 'c', 'd'});
	assert(p.Len() == 3);
	assert(p.Print(1) == "b ");
	p.Add({'e', 'f', 'g'});
	assert(p.Len() == 5);
	assert(p.Print() == "c d e f g ");
	assert(p.IsEmpty());
}

int main ()
{
	TestInt();
	cout << "TestInt done\n";
	TestChar();
	cout << "TestChar done\n";

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/e8354aa1fb51faeb)
:::
