#include <iostream>
#include <vector>
#include <string>
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

    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](string &i) {reverse(begin(i), end(i));});
    printVector(v);
}