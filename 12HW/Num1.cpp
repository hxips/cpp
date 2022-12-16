#include <iostream>
#include <vector>
using std::cout, std::cin;



int sumEven(const std::vector<int>& v)
{
	int n = v.size();
	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		if (v[i] % 2 == 0)
			sum += v[i];
	}

	return sum;
}



int main()
{
	std::vector<int> u = {56, 7, 86, 93, 47};

	cout << sumEven(u) << "\n";
}