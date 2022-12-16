#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::cin, std::endl;



std::string operator*(std::string_view str, int n)
{
	std::string res {};

	for (int i = 0; i < n; ++i)
		res += str;

	return res;
}



int main()
{
	std::string s{};

	std::cin >> s;

	int n;

	std::cin >> n;

	s = s * n;

	std::cout << s << "\n";
}