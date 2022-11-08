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


struct Library
{
	book* books;
	int number_of_books;
};
typedef struct Library library;



void print_book(book* p)
{
	printf("Book: %s, Pages: %i, Price: %0.2lf\n", p->title, p->pages, p->price);

	return;
}


void library_create(library* lib, int num)
{
	lib->books = (book*)malloc(sizeof(book) * num);

	lib->number_of_books = num;

	return;
}


void library_set(library* lib, int i, char name[], int page, float money)
{
	lib->books[i].title = (char*)malloc(sizeof(name));
	
	strcpy(lib->books[i].title, name);
	lib->books[i].pages = page;
	lib->books[i].price = money;

	return;
}


book* library_get(library* lib, int i)
{
	return &(lib->books[i]);
}


void library_print(library* lib)
{
	int n = lib->number_of_books;

	for (int i = 0; i < n; ++i)
		print_book(&(lib->books[i]));

	return;
}


void library_destroy(library* lib)
{
	int n = lib->number_of_books;

	for (int i = 0; i < n; ++i)
    {
        free(lib->books[i].title);
    }
    free(lib->books);

	return;
}



int main()
{
	library a;
	library_create(&a, 3);
	library_set(&a, 0, "Don Quixote", 1000, 750.0);
	library_set(&a, 1, "Oblomov", 400, 250.0);
	library_set(&a, 2, "The Odyssey", 500, 500.0);
	print_book(library_get(&a, 1));
	library_print(&a);
	library_destroy(&a);
}
