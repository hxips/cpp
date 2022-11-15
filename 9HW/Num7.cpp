#include <iostream>
#include "vector3f.h"
using std::cout, std::endl;


int main()
{
    Vector3f a = {5.12, 6.47, 3.1};
    Vector3f b = {0.0, -1.2, 5.12};
    cout << "a = " << a << '\n' << "b = " << b << '\n';
    cout << "a + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';
    cout << "a * 5 = " << a * 5 << " = " << 5 * a << '\n';
    cout << "a / 3 = " << a / 3 << '\n';
    cout << "a * b = " << a * b << '\n';
    cout << "-a = " << -a << '\n';
    cout << "a == b " << a == b << '\n';
    cout << "a != b " << a != b << '\n';
    cout << "a += b" << a += b << '\n';
    cout << "a -= b" << a -= b << '\n';
    cout << "a *= 6" << a *= 6 << '\n';
    cout << "b /= 2" << b /= 2 << '\n';
    normalize(b);
    cout << "Normalized b:" << b << '\n';
}