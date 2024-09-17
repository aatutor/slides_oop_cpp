::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ: Конструкторы

1. Разработать собственный класс `String`, для работы со строками (`char*`). 
1. Класс должен содержать:
	- конструктор __по умолчанию__, создающий строку длиной 80 символов
	- конструктор, создающий строку __произвольного размера__
	- конструктор, который инициализируется полученной __строкой__
	- __деструктор__
	- метод `GetStr` __возвращающий строку__
	- метод `SetStr` для инициализации __новой строкой__ (должна возвращать указатель this!)
	- метод `Len` для получения __длины__ текущей строки
1. Использовать механизмы __делегирования__ конструкторов, где это возможно - минимизировать дублирование кода.

---
### Пример использования класса
``` cpp
String str, str2(50);

String* pstr = new String("This is simple string");
cout << (pstr->GetStr()) << endl;
cout <<"Size of this line: "<< (pstr->Len()) << endl;

str2.SetStr("String updated");
cout << str2.GetStr() << " | Len: " 
				<< str2.Len() << endl;

delete pstr;
``` 

Вывод в консоли:
``` shell
This is simple string
Size of this line: 21
String updated
```

---
### Тесты
``` cpp
// #define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <iostream>

#include "String.cpp" // <- ваш файл

void TestCreate() {
	assert((char*)String("").GetStr() == std::string{""});
	assert((char*)String("123").GetStr() == std::string{"123"});
	assert((char*)String("Hello world!").GetStr() == std::string{"Hello world!"});
}
void TestLength() {
	assert(String().Len() == 80);
	assert(String(50).Len() == 50);
	assert(String("").Len() == 0);
	assert(String("hello").Len() == 5);
}
void TestInit() {
	assert((char*)String().SetStr("test")->GetStr() == std::string{"test"});
	assert((char*)String(10).SetStr("test")->GetStr() == std::string{"test"});
	assert((char*)String("").SetStr("test")->GetStr() == std::string{"test"});
	assert((char*)String("hello").SetStr("test")->GetStr() == std::string{"test"});
}
void TestClear() {
	String* pStr = new String("hello");
	char* str = pStr->GetStr();
	delete pStr;
	try {
		assert(std::string{str} != "hello");
	}
	catch (std::exception e) {
		std::cout << e.what() << "\n";
	}
}

int main ()
{
	using namespace std;
	TestCreate();
	cout << "Create done" << endl;
	TestLength();
	cout << "Length done" << endl;
	TestInit();
	cout << "Init done" << endl;
	TestClear();
	cout << "Clear done" << endl;

	return 0;
}

```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/911db53fe04ea1c0)

:::
