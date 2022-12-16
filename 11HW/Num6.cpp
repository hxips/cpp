#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::cin, std::endl;



int main()
{
	int* i = new int{123};
	cout << *i << "\n";
	delete i;

	std::string* str = new std::string{"Cats and Dogs"};
	cout << *str << "\n";
	delete str;

	int* i_arr = new int[5]{10, 20, 30, 40, 50};
	for (int j = 0; j < 5; ++j)
		cout << i_arr[j] << " ";
	cout << "\n";
	delete i_arr;

	std::string* s_arr = new std::string[3]{"Cat", "Dog", "Mouse"};
	for (int j = 0; j < 3; ++j)
		cout << s_arr[j] << " ";
	cout << "\n";

	std::string_view* s_arr_v = new std::string_view[3];
	for (int j = 0; j < 3; ++j)
		s_arr_v[j] = s_arr[j];
	for (int j = 0; j < 3; ++j)
		cout << s_arr_v[j] << " ";
	delete s_arr_v;
	delete s_arr;
}