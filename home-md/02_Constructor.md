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

[Архив презентаций](https://sourceforge.net/projects/cpp-oop-top-aca/files/Lections/active/)

[Актуальные презентации](https://aatutor.github.io/slides_oop_cpp/).

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
	var path = '/Archive2/a6/ffc2a83fcaa6b2/main.cpp';
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
