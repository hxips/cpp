#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::cin, std::endl;



void truncateToDot(std::string& s)
{
	int i = s.find(".");

	s.erase(i);

	return;
}



int main()
{
	std::string s{};

	std::cin >> s;

	truncateToDot(s);

	std::cout << s << "\n";
}