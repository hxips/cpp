#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>
using namespace std;



int main()
{
	string str;
	getline(cin, str);
	cout << all_of(str.begin(), str.end(), [](char i){return !(islower(i));});
}