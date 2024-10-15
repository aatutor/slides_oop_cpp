::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ
Описать шаблонный класс `Stack` на основе односвязного списка. Требуется реализовать типичные операции по работе со стеком.

---
### Пример использования класса
``` cpp
Stack<int> list;
list.Push(1);
list.Push(2);
list.Push(3);
cout << list.GetTop() << endl; // 3
cout << list.Extract() << endl; // 3
cout << list.GetCount() << endl; // 2
list.Pop();
cout << list.GetTop() << endl; // 1
cout << (list.IsEmpty() ? "Empty: fail" : "Not empty: ok") << endl;
list.Clear();
cout << (list.IsEmpty() ? "Empty: ok" : "Not empty: fail") << endl;
```

---
### Тесты
``` cpp
#include <assert.h>
#include <iostream>

#include "solve.h"

void TestInt() {
	Stack<int> list;
	list.Push(1);
	assert(list.GetCount() == 1);
	assert(!list.IsEmpty());
	assert(list.GetTop() == 1);
	assert(list.Extract() == 1);
	assert(list.GetCount() == 0);
	assert(list.IsEmpty());
	list.Push(2);
	list.Push(3);	
	assert(list.GetCount() == 2);
	assert(list.GetTop() == 3);
	list.Pop();
	assert(list.GetCount() == 1);
	assert(list.GetTop() == 2);
	list.Clear();
	assert(list.GetCount() == 0);
	assert(list.IsEmpty());
}

int main ()
{
	using namespace std;
	TestInt();
	cout << "TestInt done\n";

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/bef7b60682c2f4ba)
:::