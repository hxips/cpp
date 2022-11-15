#include <cstdio>
#include <iostream>
#include <ctype.h>



namespace myspace
{
	/* Num 1 */
	void printNTimes(const char* str, int n = 10)
	{
		for (int i = 0; i < n; ++i)
			std::cout << str << ' ';

		return;
	}


	/* Num 2 */
	int cubeV(int n)
	{
		return n * n * n;
	}


	/* Num 3 */
	int cubeR(const int& n)
	{
		int cube =  n * n * n;

		return cube;
	}


	/* Num 4 */
	void countLetters(const char* str, int& numLetters, int& numDigits, int& numOthers)
	{
		int i = 0;

		while(str[i] != '\0')
		{
			if (isalpha(str[i]))
				++numLetters;

			else if (isdigit(str[i]))
				++numDigits;

			else
				++numOthers;

			++i;
		}

		return;
	}


	/* Num 5 */
	struct book
	{
		char title[100];
		int pages;
		float price;
	};

	void addPrice(book& b, float x)
	{
		b.price += x;

		return;
	}


	/* Num 6 */
	bool isExpensive(const book& b)
	{
		if (b.price > 1000)
			return true;

		else
			return false;
	}

}





int main()
{
	int m = 10;
	char string[5] = "MIPT";
	const char* s = &string[0];

	/* test Num 1 */
	myspace::printNTimes(s, m);

	/* test Num 2 */
	std::cout << '\n' << myspace::cubeV(m) << '\n';

	/* test Num 3 */
	std::cout << myspace::cubeR(m) << '\n';

	/* test Num 4 */
	char srt[10] = "iT6*b%b 3";
	const char* s2 = srt;
	int dig = 0;
	int let = 0;
	int oth = 0;

	myspace::countLetters(s2, let, dig, oth);
	std::cout << let << ", " << dig << ", " << oth << '\n';

	/*test Num5*/
	myspace::book hop = {"Trom", 54917, 51.23};
    myspace::book& h = hop;

    myspace::addPrice(h, 2300.164);
    std::cout << h.price << "\n";

    /* test Num6 */
    std::cout << myspace::isExpensive(hop) << '\n';
}