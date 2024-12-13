::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

1. Описать класс `Company` 
	- со следующими полями (`string`):
		- Название фирмы
		- Телефон
		- Адрес
		- ОКВЕД
	- а также перегрузку оператора `<<` для вывода иноформации в файл

2. Описать класс `CompanyList` для работы со списком компаний. Долже иметь метод `SaveTo`, для сохранения списка по указанному пути.

---
### Пример использования класса
``` cpp
{
	Company c("A", "B", "C", "000");
	fstream file("test.txt", ios::out);
	file << c << endl;
	file.close();
}
PrintFile("test.txt");

{
	list<Company> arr{
		Company("MTS", "8 800 250 0890", "Moskow", "61.20"),
		Company("Rambler", "(495) 7713015", "Moskow", "06.10"),
		Company("Yandex", "1600", "Moskow", "62.01")
	};
	CompanyList list(arr);
	list.SaveTo("list.txt");
}
PrintFile("list.txt");
```

``` cpp
void PrintFile(std::string filename) {
	std::fstream fs(filename, std::ios::in);
	std::string line;
	while(!fs.eof()) {
		getline(fs, line);
		std::cout << line << std::endl;
	}
	fs.close();
	std::cout << std::string(15, '-') << std::endl;
}
```

---
cmd:
``` shell
A (B - C) OKVED: 000
---------------
MTS (8 800 250 0890 - Moskow) OKVED: 61.20
Rambler ((495) 7713015 - Moskow) OKVED: 06.10
Yandex (1600 - Moskow) OKVED: 62.01
---------------
```

[Примеры с презентаций (github)](https://github.com/aatutor/oop_cpp_files)

[Презентации](https://aatutor.github.io/slides_oop_cpp/) | [Архив](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

## [Проверить решение онлайн](https://coliru.stacked-crooked.com/a/c02aa927f45bf493)
:::
