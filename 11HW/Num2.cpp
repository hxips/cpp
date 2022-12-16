#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::cin, std::endl;

std::string repeat1(std::string s)
{
	return s + s;
}


void repeat2(std::string& s)
{
	s.append(s);

	return;
}


void repeat3(std::string* ps)
{
	*ps += *ps;

	return;
}


std::string* repeat4(std::string s)
{
	std::string* p = new std::string[1] {s + s};

	return p;
}



int main()
{
	std::string str{};

	std::cin >> str;

	std::cout << repeat1(str) << "\n";

	repeat2(str);
	std::cout << str << "\n";

	std::string* p = &str;
	repeat3(p);
	std::cout << str << "\n";

	std::cout << *repeat4(str) << "\n";
}