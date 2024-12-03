::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ

1. Описать класс `Company` 
	- со следующими полями (`string`):
		- Название фирмы
		- Телефон
		- Адрес
		- ОКВЭД
	- а также перегрузку оператора `<<` для вывода иноформации в файл

2. Описать класс `CompanyList` для работы со списком компаний. Должен иметь метод `SaveTo`, для сохранения списка по указанному пути.

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

## [Проверить решение онлайн]()
---
<!-- .slide: data-visibility="hidden" -->
## Эксперементальный способ автопроверки:

<textarea id="code" placeholder="МЕСТО ДЛЯ ВАШЕГО КОДА">
</textarea>
<button id="run">Запустить пример</button>
<button id="test" hidden="hidden">Запустить тест</button>
<div id="result" style="min-height: 500px"> ^^^ вставить код для проверки</div>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
<script>
	var path = '/Archive2/69/0a33fd790b09cf/main.cpp';
	function test(files, args) {
		var http = new XMLHttpRequest();
		http.open("POST", "http://coliru.stacked-crooked.com/compile", false);
		var makeLink = (p, n) => { return "ln -s " + p + ' ' + n + " && " };
		var cmnd = files.map(f => makeLink(f.path, f.name)).join('');
		var names = files.map(f => f.name).join(' ');
		var cmd = cmnd +" ln -s main.cpp solve.cpp && "+ "g++ -std=c++11 -std=gnu++11 "+names+(args ? " "+args :'')+" && ./a.out";
		console.log(cmd);
		http.send(JSON.stringify({ "cmd": cmd, "src": $("#code").val() }));
		console.log(http.response);
		// console.log(http);
		var res = $('<code>');
		http.response.split('\n').forEach(function(line) {
			res.append( $('<tr>').append( $('<td>').html(line)) ); 
		});
		$("#result").html($('<pre>', {'class': 'hljs'}).append(res) );
	}
	$(document).ready(function(){
		$("button#run").click(function(){ test([{path : path, name : 'temp.cpp'}], '-DPUB'); });
		$("button#test").click(function(){ test([{path : path, name : 'temp.cpp'}]); });
	});
</script>
:::
