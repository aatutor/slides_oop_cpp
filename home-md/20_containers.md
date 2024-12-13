::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

- Опишите класс `Dictionary` для хранения списка слов. Словарь хранит список уникальных слов. 
- Реализовать методы:
	- `Add` - добавление слова в словарь;
	- `Delete` - удаление слова из словаря;
	- `Edit` - редактирование слова;
	- `Save` - сохранение словаря в файл;
	- `Load` - загрузка словаря из файла;
	- `Print` - печать словаря в консоль.

*Рекомендация: при реализации воспользуйтесь классом `std::set`*

---
### Пример использования класса
``` cpp
{
	Dictionary dict;
	
	dict.Add("hello");
	dict.Add("world");
	dict.Add("words");
	dict.Add("is");
	dict.Add("unique");
	dict.Add("and");
	dict.Add("it");
	dict.Add("is");
	dict.Add("unique");

	dict.Delete("hello");
	dict.Edit("world", "war");
	
	dict.Save("text.txt");
}
{
	Dictionary dict;
	dict.Load("text.txt");

	dict.Print();
}	
```

---
cmd:
``` shell
and
is
it
unique
war
world
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/2b35c56d2994436a)
:::
