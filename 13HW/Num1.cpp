#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return;
}



int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	vector<int>::iterator it = max_element(v.begin(), v.end());

	sort(v.begin(), it);
	sort(it, v.end(), [](int a, int b){return a > b;});
	printVector(v);
}
