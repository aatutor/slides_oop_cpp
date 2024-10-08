::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

- Есть строка символов, признаком конца которой является «`;`». В строке могут быть скобки (`{}`, `()`, `[]`) . Необходимо проверить корректность расстановки скобок:

	1. Каждая открывающая скобка должна иметь справа такую же закрывающую. Обратное также должно быть верно.

	1. Открывающие и закрывающие пары скобок разных типов должны быть правильно расположены по отношению друг к другу.
- Пример правильной строки: `({x-y-z}*[x+2y]-(z+4x));`
- Пример неправильной строки: `([x-y-z}*[x+2y)-{z+4x)].`	

---
### Вариант: функция
- Опишите функцию (`CheckBrackets`), реализующую это задание: 
	- Если все условия выполнены, то функция вернет `-1`. 
	- Если нет - то индекс некорректного символа строки.
### Вариант: класс
- Опишите класс(`Checker`), реализующий это задание: 
	- конструктор, принимающий строку для проверки
	- метод `IsCorrect` - возвращает результат проверки (`bool`)
	- метод `GetWrongIndex` - возвращает индекс первого некорректного символа (-1, если все верно)
	- метод `GetStringResult` - возвращает строку до первой некорректной скобки

---
### ВАЖНО!
- Внутри используйте класс `Stack` (или `std::stack`) для реализации задачи.
- <u>**ВАЖНО!**</u> Класс `Stack` должен оставаться <u>универсальным</u> - не нужно править его под данную задачу, его нужно лишь <u>ИСПОЛЬЗОВАТЬ!</u>
	- Если вы используете `std::stack` из библиотеки, то это условие выполнится автоматически.

<!-- ---
- Внутри используйте класс `Stack` (или `std::stack`) для его реализации.
	- **ВАЖНО!** Класс `Stack` должен оставаться универсальным - не нужно править его под данную задачу, его нужно лишь <u>ИСПОЛЬЗОВАТЬ!</u>
	- Если вы используете `std::stack` из библиотеки, то это условие выполнится автоматически. -->

---
### Пример использования функции
``` cpp
Checker b("({x-y-z}*[x+2y]-(z+4x));");
cout << ( b.IsCorrect() ? "correct" : "wrong" )  << endl;

Checker c("([x-y-z}*[x+2y)-{z+4x)].");
if (c.IsCorrect() == false) {
	cout << "wrong at: " << c.GetWrongIndex() << endl;
	cout << c.GetStringResult() << endl;
}
```
``` cpp
cout << CheckBrackets("1;") << endl;
cout << CheckBrackets(")(") << endl;
cout << CheckBrackets("[3x4y]") << endl;
```


---
### Тесты
``` cpp
#include <assert.h>
#include <iostream>

#include "solve.h"
#if LVL_CLASS
int CheckBrackets(std::string str) {
	Checker c(str);
	return c.GetWrongIndex();
}
#endif
void TestBrackets() {
	assert( CheckBrackets("({x-y-z}*[x+2y]-(z+4x));") == -1 );
	assert( CheckBrackets("([x-y-z}*[x+2y)-{z+4x)].") == 7 );
	assert( CheckBrackets("1;") == -1 );
	assert( CheckBrackets(")(") == 0 );
	assert( CheckBrackets("[3x4y]") == 6 );
}
int main ()
{
	TestBrackets();
	std::cout << "Brackets done\n";

	return 0;
}
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/8e8736a18325cb23)
:::
