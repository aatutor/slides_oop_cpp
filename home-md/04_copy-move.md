::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ: Копирование и перемещение

Добавьте к существующему классу `String`:
- конструктор __копирования__ (от другого объекта строки)
- конструктор __перемещения__ (аналогично)

---
### Пример использования класса
``` cpp
{
	String* s1 = new String("Copy");
	String s2(*s1);
	delete s1;
	cout << s2.GetStr() << endl; // Copy
}
{
	String s( std::move(String("Move")) );
	cout << s.GetStr() << endl; // Move
}
```

---
### Тесты
``` cpp
#include <assert.h>
#include <iostream>
#include <string>

#include "String.cpp"

void TestCopy() {
	String s1("test");
	String s2 = s1;
	s1.SetStr("");
	assert((char*)s2.GetStr() == std::string{"test"});
}
void TestMove() {
	String s( 1 ? String("test") : String() );
	assert((char*)s.GetStr() == std::string{"test"});
}

int main ()
{
	using namespace std;
	TestCopy();
	cout << "Copy done\n";
	TestMove();
	cout << "Move done\n";

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/7e0ec80191b655d6)

:::
