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

## [Проверить решение онлайн]()
---
<!-- .slide: data-visibility="hidden" -->
## Эксперементальный способ автопроверки:

<textarea id="code" placeholder="МЕСТО ДЛЯ ВАШЕГО КОДА">
</textarea>
<button id="run">Запустить пример</button>
<button id="test">Запустить тест</button>
<div id="result" style="min-height: 500px"> ^^^ вставить код для проверки</div>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
<script>
	var path = '/Archive2/37/1c1853c775cbd3/main.cpp';
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
