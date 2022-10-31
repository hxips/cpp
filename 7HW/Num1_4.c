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
    book* p = (book*)malloc(sizeof(book));

    strcpy(p->title, "Don Quixote");

    p->pages = 1000;

    p->price = 750.0;

    printf("Book: %s, Pages: %i, Price: %0.2lf\n", p->title, p->pages, p->price);

    free(p);
}