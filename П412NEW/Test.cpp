#include "Test.h"

void start_test_string_class()
{
	cout << "=*= ^Тесты класса String^ =*=" << endl;

	cout << "Конструкторы:" << endl;
	String s1;
	String s2("Hello");
	String s3('!');
	String s4(s2);
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "size s2: " << s2.size() << endl;
	cout << "-------------\n\n";

	cout << "Присваивание:" << endl;
	s1 = "World";
	cout << "s1: " << s1 << endl;
	s4 = s1;
	cout << "s4: " << s4 << endl;
	cout << "-------------\n\n";

	cout << "Конкатенация:" << endl;
	String s5 = s2 + ", " + s1 + s3;
	cout << "s5: " << s5 << endl;
	s5 += "!!";
	cout << "s5: " << s5 << endl;
	cout << "-------------\n\n";

	cout << "Доступы по индексу:" << endl;
	for (unsigned int i = 0; i < s5.size(); i++)
	{
		cout << s5[i] << ' ';
	}
	cout << "\n\n-------------\n\n";

	cout << "Сравнение:" << endl;
	String a("abc");
	String b("abf");
	cout << "a == b: " << (a == b) << endl;
	cout << "a != b: " << (a != b) << endl;
	cout << "a < b: " << (a < b) << endl;
	cout << "a > b: " << (a > b) << endl;
	cout << "-------------\n\n";

	cout << "Поиск и редактирование:" << endl;
	String text("   C++ String class example   ");
	cout << text << endl;
	cout << "substr(3,3): " << text.substr(3, 3) << endl;
	cout << "find('S'): " << text.find('S') << endl;
	cout << "find(\"example\"): " << text.find("example") << endl;
	text.trim();
	cout << "После trim(): " << text << endl;
	text.to_upper();
	cout << "После to_upper(): " << text << endl;
	text.to_lower();
	cout << "После to_lower(): " << text << endl;
	text.reverse();
	cout << "После reverse(): " << text << endl;
	cout << "-------------\n\n";


	cout << "starts_with / ends_witch:" << endl;
	String prefix("C++");
	String suffix("elpmaxe");
	cout << prefix << " -> " << text.starts_with(prefix) << endl;
	cout << suffix << " -> " << text.ends_with(suffix) << endl;
	cout << "-------------\n\n";

	cout << "Ввод строки:" << endl;
	String input;
	cout << "Введите слово: ";
	cin >> input;
	cout << "Вы ввели: " << input << endl;
	cout << "-------------\n\n";
}

void start_test_names_matrix_class()
{
	cout << "=*= ^Тесты класса NamesMatrix^ =*=" << endl;

	NamesMatrix nm1(3, 2, 2);
	nm1.fill_names("Prefix");
	nm1.fill_matrix("Cell");

	cout << "Исходный nm1: " << endl;
	nm1.print(cout);
	cout << endl;

	NamesMatrix nm2(nm1);

	cout << "После копирующего конструктора nm2 (копия nm1): " << endl;
	nm2.print(cout);
	cout << endl;

	nm1.name(0) = "SWITCH_PREFIX_0";
	nm1.at(0, 0) = "SWITCH_CELL_0_0";

	cout << "После изменения nm1: " << endl;
	nm1.print(cout);
	cout << endl;

	cout << "После изменения nm2: " << endl;
	nm2.print(cout);
	cout << endl;

	NamesMatrix nm3;
	nm3 = nm1;

	cout << "После изменения nm3: " << endl;
	nm3.print(cout);
	cout << endl;

	nm3.name(1) = "SWITCH_PREFIX_1";
	nm3.at(1, 1) = "SWITCH_CELL_1_1";

	cout << "После изменения nm3: " << endl;
	nm3.print(cout);
	cout << endl;

	cout << "Финальная проверка после всех изменений nm1: " << endl;
	nm1.print(cout);
}