#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Book
{
    char* title;
    int pages;
    float price;
};
typedef struct Book book;



int main()
{
    book* p = (book*)malloc(3 * sizeof(book));
    
    p[0].title = (char*)malloc(12 * sizeof(char));
    strcpy(p[0].title, "Don Quixote");

    p[1].title = (char*)malloc(8 * sizeof(char));
    strcpy(p[1].title, "Oblomov");

    p[2].title = (char*)malloc(12 * sizeof(char));
    strcpy(p[2].title, "The Odyssey");

    p[0].pages = 1000;
    p[1].pages = 400;
    p[2].pages = 500;

    p[0].price = 750.0;
    p[1].price = 250.0;
    p[2].price = 500.0;


    printf("Book: %s, Pages: %i, Price: %0.2lf\n", p[0].title, p[0].pages, p[0].price);
    printf("Book: %s, Pages: %i, Price: %0.2lf\n", p[1].title, p[1].pages, p[1].price);
    printf("Book: %s, Pages: %i, Price: %0.2lf\n", p[2].title, p[2].pages, p[2].price);

    free(p[2].title);
    free(p[1].title);
    free(p[0].title);
    free(p);
}