#include <stdio.h>


int main()
{
    printf("char:\t%i\n", sizeof(char));

    printf("short:\t%i\n", sizeof(short));

    printf("int:\t%i\n", sizeof(int));

    printf("long long:\t%i\n", sizeof(long long));

    printf("size_t:\t%i\n", sizeof(size_t));

    printf("float:\t%i\n", sizeof(float));

    printf("double:\t%i\n", sizeof(double));

    printf("int*:\t%i\n", sizeof(int*));

    int arr[10];
    printf("int[10]:\t%i\n", sizeof(arr));
}