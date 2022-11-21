#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

/*
    Класс Number -- класс положительных больших чисел

    Большое число будет храниться в динамическом массиве data
    Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления
    (так как base = 100)
    По сути, каждый элемент data хранит две цифры числа в десятичной записи

    Значение 100 для системы счисления выбрано как компромис между
    эффективностью и удобством написания программы.
    Если выбрать значения базы 10 - то программа будет не так эффективна по памяти
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
    то алгоритм печати на экран сильно усложнится
    В качестве альтернативы, можно было выбрать базу 1e9,
    изменив при этом тип элементов c char на int

    capacity - размер массива data
    size - сколько ячеек занимет число в массиве data
    size <= capacity

    Для удобства разряды числа хранятся в обратном порядке
    Например, число 12345678 соответствует массиву
    data = {78, 56, 34, 12}
    (это упрощает многие алгоритмы с такими числами)
*/


class Number
{
private:
    static const int base = 100;
    std::size_t size;
    std::size_t capacity;
    char* data;

public:

    Number(int a)
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0)
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0)
            capacity = 1;

        // Выделяем память и записывем число a в массив data
        // Например, число 12345678 представится в виде массива [78, 56, 34, 12]

        data = new char[capacity];

        for (int i = 0; i < capacity; ++i)
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }

    Number()
    {
        size = 1;
        capacity = 1;
        data = new char[1];
        data[0] = 0;
    }


    Number(const Number& n)
    {
        capacity = n.capacity;
        size = n.size;

        data = new char[capacity];

        for (int i = 0; i < size; ++i)
            data[i] = n.data[i];
    }


    Number(const char* str)
    {
        int k = 0;

        while (str[k] != '\0')
        {
            ++k;
        }

        size = (k + 1) / 2;
        capacity = (k + 1) / 2;
        data = new char[capacity];


        int start = 0;

        if (k % 2)
        {
            data[size - 1] = (int)(str[0] - '0');

            start = 1;
        }

        --k;

        for (start; start < k; start += 2)
        {
            data[size - 1 - ((start + 1) / 2)] = 10 * (int)(str[start] - '0') + (int)(str[start + 1] - '0');
        }
    }

    Number& operator=(const Number& right)
    {
        capacity = right.capacity;
        size = right.size;

        data = new char[capacity];
        for (int i = 0; i < capacity; ++i)
            data[i] = right.data[i];

        return *this;
    }


    Number operator+(const Number& right)
    {
        Number res;

        if (size < right.size)
        {
            res.size = right.size;
            res.capacity = right.size + 1;
        }
        else
        {
            res.size = size;
            res.capacity = size + 1;
        }

        res.data = new char[res.capacity];
        for (int i = 0; i < size; ++i)
            res.data[i] = data[i];

        if (right.size > size)
        {
            for (int i = size; i < res.capacity; ++i)
                res.data[i] = 0;
        }


        int add = 0;
        int sum = 0;

        for (int i = 0; i < right.size; ++i)
        {
            sum = res.data[i] + right.data[i] + add;
            res.data[i] = sum % base;
            add = sum / base;
        }

        for (int i = right.size; i < res.size; ++i)
        {
            sum = res.data[i] + add;
            res.data[i] = sum % base;
            add = sum / base;
        }

        if (add != 0)
        {
            res.data[res.size] = add;
            ++res.size;
        }

        return res;
    }

    Number& operator+=(const Number& right)
    {
        *this = (*this + right);

        return *this;
    }


    bool isEven()
    {
        return (data[0] % 2 == 0);
    }

    Number operator*(const Number& right)
    {
        Number res;

        if (size < right.size)
        {
            res.size = right.size;
            res.capacity = right.size + 2;
        }
        else
        {
            res.size = size;
            res.capacity = size + 2;
        }

        res.data = new char[res.capacity];
        for (int i = 0; i < res.size; ++i)
            res.data[i] = 0;


        int add = 0;
        Number mult;

        for (int j = 0; j < size; ++j)
        {
            mult = 0;

            for (int i = 0; i < right.size; ++i)
            {
                mult += data[j] * right.data[i];
            }

            res += mult;
        }

        if (add != 0)
        {
            res.data[res.size] = add;
            ++res.size;
        }

        return res;
    }

    ~Number()
    {
        delete[] data;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& right);
    friend Number fibanacci(int n);
};


Number fibanacci(int n)
{
    Number res;

    if (n == 0)
    {
        return Number(0);
    }
    else if (n == 1)
    {
        return Number(1);
    }

    else
    {
        Number* fib = new Number[2];
        fib[0] = 0;
        fib[1] = 1;

        for (int i = 2; i <= n; ++i)
            fib[i % 2] = fib[0] + fib[1];

        res = fib[n % 2];
    }

    return res;
}


std::ostream& operator<<(std::ostream& stream, const Number& right)
{
    // Печатаем самый большой разряд
    stream << (int)right.data[right.size - 1];

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw это то же самое, что и в языке C спецификатор %02d
    for (std::size_t i = 0; i < right.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << (int)right.data[right.size - 2 - i];

    return stream;
}



int main()
{
    Number x = 12345;
    Number y = 0;
//    std::cout << x << " " << y << std::endl;

    Number a(459);
    Number b(a);
//    Number c("659111515154545455656194515");
//    Number d("4898545552164545454");
//    Number e = a;
//    Number f = (c + d);
//    std::cout << a << " " << b << " " << c << " " << d << " " << e << std::endl;
//    std::cout << f << std::endl;
//    f += c;
//    std::cout << f << std::endl;
//    Number g = fibanacci(1000);
//    std::cout << g << std::endl;
//    std::cout << a.isEven() << std::endl;
    Number h = (a * b);
    std::cout << h << std::endl;
}