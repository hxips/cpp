#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;



int main()
{
	std::string str {};
	std::cin >> str;

	if (isupper(str[0]))
		str[0] += 32;

	else if (islower(str[0]))
		str[0] -= 32;

	std::cout << str << '\n';
}