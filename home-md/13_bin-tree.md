::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

Описать структуру `Ticket` - штрафная квитанция за нарушения ПДД с полями:
- `type` - вид правонарушения
- `carNumber` - номер автомобиля
- `cost` - размер штрафа
- `paid` - оплачена ли квитанция
- `id` - уникальный идентификатор квитанции

---
Реализовать базу данных ГАИ (класс `ForfeitDB`) по штрафным квитанциям с помощью бинарного дерева. Ключом будет служить `carNumber`. Реализовать следующие методы:
- `Add(Ticket)` - Добавление правонарушения
- `PrintAll()` - Полная распечатка базы данных
- `Print()` - Распечатка актуальных(не оплаченных) правонарушений
- `Print(number)` - Распечатка данных по указанному авто
- `GetTickets(number)` - возвращает `std::list` с квитанциями по указанному авто
- `Delete(Ticket)` - поиск и удаление квитанции

---
<u>***Важно!***</u> 
- Класс `Tree`, описанный на занятии должен быть **шаблонным** и использован по следующей схеме **вложенности**:
	- `ForfeitDB` -> `Tree` -> `Node` -> `Ticket`
- Поэтому можно реализовать вариант класса `Tree`, как работающий с объектами `Ticket`, так и с указателями `Node`(элементами дерева). Главное сохранить <u>**универсальную**</u> реализацию дерева, а не делать его пригодным лишь для данной задачи.

---
### Пример использования класса
``` cpp
std::initializer_list<Ticket> list = {
	Ticket{ "speed limit", "a123bc", 1000 },
	Ticket{ "speed limit", "z999zz", 1000, true },
	Ticket{ "red light", "a123bc", 5000 },
	Ticket{ "red light", "a000aa", 5000 },
	Ticket{ "red light", "a000aa", 5000, true },
	Ticket{ "drunk", "w555ww", 100000 }
};
ForfeitDB db;
for (const Ticket i : list) {
	db.Add(i);
}
db.PrintAll();
db.GetTickets("a123bc").begin()->paid = true;
cout << "\nActual:\n";
db.Print();
db.Delete(*db.GetTickets("w555ww").begin());
cout << "\nRemoved 'drunk':\n";
db.Print();
```

---
cmd:
``` shell
a000aa: { [id:4] red light: 5000rub (-) }{ [id:5] red light: 5000rub (+) }
a123bc: { [id:1] speed limit: 1000rub (-) }{ [id:3] red light: 5000rub (-) }
w555ww: { [id:6] drunk: 100000rub (-) }
z999zz: { [id:2] speed limit: 1000rub (+) }

Actual:
a000aa: { [id:4] red light: 5000rub (-) }
a123bc: { [id:3] red light: 5000rub (-) }
w555ww: { [id:6] drunk: 100000rub (-) }
z999zz: - all_tickets_paid -

Removed 'drunk':
a000aa: { [id:4] red light: 5000rub (-) }
a123bc: { [id:3] red light: 5000rub (-) }
w555ww: - all_tickets_paid -
z999zz: - all_tickets_paid -
```
---

### [Онлайн проверка](https://coliru.stacked-crooked.com/a/8f16aa7f28de6dff)
[Исходники тестов](https://coliru.stacked-crooked.com/a/2719d5dfdc9648f4)

---
[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)
:::
