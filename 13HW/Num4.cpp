#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>



bool isIdentifier(std::string_view s)
{
	if (!(isalpha(s[0])) && s[0] != '_')
		return false;

	return std::all_of(s.begin(), s.end(), [](char i){return (isalpha(i) || isdigit(i) || (i == '_'));});
}



int main()
{
	std::string str;
	std::getline(std::cin, str);
	std::cout << isIdentifier(str);
}