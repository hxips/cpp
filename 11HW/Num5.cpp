#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::cin, std::endl;



int sum_string(std::string_view s)
{
	int i = s.length() - 1;
	int p = 1;
	int sum = 0;

	while (i >= 0)
	{
//		if (isdigit(s[i]))
//		{
//			int m = s[i] - 48;
//			cout << "m: " << m << "\n";
//			cout << "m * p: " << m * p << "\n";
//			cout << "s[i]: " << s[i] << "\n";
//			cout << "s[i] * p: " << int(s[i]  * p) << "\n";
//			sum += (s[i] - 48) * p;
//			cout << "sum: " << sum << "\n";
//			p *= 10;
//		}
//
//		else
//		{
//			p = 1;
//			cout << "p: " << p << "\n";
//		}
//
//		--i;

		p = 1;

		while (isdigit(s[i]))
		{
			sum += (s[i] - 48) * p;
			p *= 10;

			--i;
		}

		--i;
	}

	return sum;
}



int main()
{
	std::string s{};

	getline(std::cin, s);

	std::cout << sum_string(s) << "\n";
}