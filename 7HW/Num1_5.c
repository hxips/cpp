#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Book
{
    char title[50];
    int pages;
    float price;
};
typedef struct Book book;



int main()
{
    book b = {"Don Quixote", 1000, 750.0};

    book** p = (book**)malloc(sizeof(book*));

    **p = b;

    printf("Book: %s, Pages: %i, Price: %0.2lf\n", (**p).title, (**p).pages, (**p).price);

    free(p);
}
