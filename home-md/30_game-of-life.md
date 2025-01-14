::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ: Игра в жизнь (#1)

Для реализации симуляции в стиле ООП, необходимо динамически описать расширение пространства для будущих клеток. Необходима возможность как расширения, так и уменьшения "бесконечного" пространства. Поэтому для начала реализуем одномерное пространство (массив).

---
-  Объявить шаблонный класс `ShiftList` для работы с массивом со смещением, динамически расширяемым в обе стороны, из-за чего индексы могут быть отрицательными, т.е. начинаться не с "0". Описать следующие методы:
	- `Min`, `Max` - реальные границы массива (крайние индексы)
	- `PushFront`, `PushBack` - вставка элемента в концы массива
	- `PopFront`, `PopBack` - удаление элемента с концов массива
	- `(obj)[i]` - перегрузку для обращения к элементу по индексу
	- `(obj) >> cout` - перегрузка для работы с потоком вывода

*Подсказка: Для простоты работы с памятью можно хранить элементы в `std::list` или `std::vector`.*

---
### Пример использования класса
``` cpp
ShiftList<int> list(3, -1); // 3 элемента, начиная с [-1]-го

cout << "range: " << list.Min() << " : " << list.Max() << endl;

for (int i = list.Min(); i <= list.Max(); ++i)
	list[i] = i;

list.PushFront(9);
list.PushBack(99);

list >> cout;

cout << "range: " << list.Min() << " : " << list.Max() << endl;

list.PopFront();
list.PopBack();

list >> cout;

cout << "range: " << list.Min() << " : " << list.Max() << endl;
```

---
cmd:
``` shell
range: -1 : 1
list: 9 -1 0 1 99
range: -2 : 2
list: -1 0 1
range: -1 : 1
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/e59c1038a2941117)
:::
