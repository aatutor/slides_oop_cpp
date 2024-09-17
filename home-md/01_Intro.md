::: home-md 
<!-- .element: hidden="hidden" -->

### ДЗ: Введение

В файле `Fraction.cpp` реализуйте класс `Fraction` (дробь). Необходимо хранить в качестве полей (переменных-членов класса) числитель и знаменатель.
Реализуйте методы (функции-члены класса) : 
- `Init` - для ввода данных в поля
- `ToString` - возвращает дробь в виде строки
- `GetNumerator` - метод, возвращающий числитель
- `GetDenominator` - метод, возвращающий знаменатель
- и выполнения арифметических операций:
	- `Sum` - сложение
	- `Sub` - вычитание
	- `Mult` - умножение
	- `Div` - деление

Также вам будет необходимо сокращать дробь, при необходимости.
Поля должны быть приватными.

---
### Пример использования класса в двух вариантах (на выбор)
``` cpp
#if LVL_EASY /// вариант на выбор (1,0):
	Fraction a, b;
	a.Init(1, 2);
	b.Init(3, 4);
	double x = a.Sum(b);
	cout << a.ToString() << endl; // 1/2
	cout << b.ToString() << endl; // 3/4
	cout << x << endl;// 1.25
#else
	Fraction a, b;
	a.Init(1, 2);
	b.Init(3, 4);
	Fraction c = a.Sum(b);
	cout << a.ToString() << endl; // 1/2
	cout << b.ToString() << endl; // 3/4
	cout << c.ToString() << endl; // 5/4
#endif
```

---
### Тесты
``` cpp
#include <assert.h>
#include <iostream>
using namespace std;

#include "Fraction.cpp"

#define LVL_EASY 1 /// выберите вариант (1,0):

bool operator==(Fraction a, Fraction b) {
	return a.GetNumerator() == b.GetNumerator() && a.GetDenominator() == b.GetDenominator();
}
bool operator!=(Fraction a, Fraction b) {
	return !(a == b);
}
Fraction CreateFraction(int numerator, int denominator) {
	Fraction a;
	a.Init(numerator, denominator);
	return a;
}
void Test1() {
	Fraction a, b;
	a.Init(1, 2);
	b.Init(3, 4);
	
#if LVL_EASY
	assert((a.Sum(b) == 1.25));
	assert((a.Sub(b) == -0.25));
	assert((a.Mult(b) == 3.0/8));
	assert((a.Div(b) - 2.0/3) < 0.0000001);
#else
	assert((a.Sum(b) == CreateFraction(5, 4)));
	assert((a.Sub(b) == CreateFraction(-1, 4)));
	assert((a.Mult(b) == CreateFraction(3, 8)));
	assert((a.Div(b) == CreateFraction(2, 3)));
#endif

	assert((a == CreateFraction(1, 2)));
	assert((b == CreateFraction(3, 4)));
}

int main() 
{
	Test1();

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
	var path = '/Archive2/45/4654971e570f3c/main.cpp';
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
