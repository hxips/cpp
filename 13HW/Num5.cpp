#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>



std::string move_spaces(std::string_view s)
{
	std::string res(s.size(), 0);

	std::copy_if(s.begin(), s.end(), res.begin(), [](char i){return i != ' ';});

	std::string::reverse_iterator it = res.rbegin();
	std::copy_if(s.begin(), s.end(), it, [](char i){return i == ' ';});	

	return res;
}



int main()
{
	std::string str;
	std::getline(std::cin, str);
	std::cout << move_spaces(str);
}