/*
    В данной программе мы считываем содержимое файлов actors.csv и movies.csv в одну структуру MovieDatabase.
    Структура MovieDatabase это примитивная база данных, в которой хранятся данные о фильмах и актёрах.
    
    Структура Actor состоит из следующих полей:

        1)  name        - имя актёра
        2)  surname     - фамилия актёра
        3)  gender      - пол, 0 - мужской, 1 - женский (тут можно было использовать enum)
        4)  height      - высота актёра в сантиметрах
        5)  birth_date  - дата рождения, структура, которая состоит из трёх полей типа int
        6)  birth_address - место рождения, структура, которая состоит из трёх полей - строк.


    Структура Movie состоит из следующих полей:

        1)  title        - название фильма
        2)  release_date - дата выхода, структура типа Date
        3)  rating       - рейтинг фильма, число от 0 до 10
        4)  crew_size    - количество актёров, сыгравших в фильме
        5)  crew         - массив, содержащий индексы актёров из массива, в котором хранятся актёры

    Структура MovieDatabse состоит из следующих полей:

        1)  number_of_movies    - количество фильмов в базе
        2)  movies              - массив фильмов
        3)  number_of_actors    - количество актёров в базе
        4)  actors              - массив актёров


    Были написаны функции для работы с этими структурами:

        read_actors_from_file:

            Эта функция принимает на вход название файла и указатель на первый элемент массива структур Actor.
            При этом подразумевается, что массив достаточно большой, чтобы сохранить всех актёров из файла.
            Функция считывает всех актёров из файла в массив и возвращает количество считанных актёров.


        read_movies_from_file:

            Эта функция принимает на вход название файла и указатель на первый элемент массива структур Movie.
            При этом подразумевается, что массив достаточно большой, чтобы сохранить все фильмы из файла.
            Функция считывает все фильмы из файла в массив и возвращает количество считанных фильмов.


        read_database:

            Эта функция принимает на вход названия файлов в которых хранятся данные о актёрах и фильмах.
            А также эта функция принимает указатель на структуру типа MovieDatabase.
            Функция считывает все данные из файлов в одну структур типа MovieDatabase.

        
        print_actor:

            Печатаем данные об одном актёре в поток stream. stream может быть или файлом или stdout.

        print_movie:

            Печатаем данные об одном фильме в поток stream. stream может быть или файлом или stdout.

        print_movie_descriptive

            Печатаем подробные данные об одном фильме в поток stream. stream может быть или файлом или stdout.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>



struct date
{
    int day, month, year;
};
typedef struct date Date;


struct address
{
    char country[12];
    char region[52];
    char city[32];
};
typedef struct address Address;


struct actor
{
    char name[32];
    char surname[32];
    int gender;
    int height;
    Date birth_date;
    Address birth_address;
};
typedef struct actor Actor;


struct movie
{
    char title[50];
    Date release_date;
    double rating;

    int crew_size;
    int crew[20];
};
typedef struct movie Movie;


struct movie_database
{
    int number_of_movies;
    Movie movies[5000];

    int number_of_actors;
    Actor actors[5000];
};
typedef struct movie_database MovieDatabase;



int read_actors_from_file(const char* filename, Actor* actors)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        fprintf(stdout, "Error. Can't open file %s!", filename);
        exit(1);
    }
    int number_of_actors;
    fscanf(fin, "%i", &number_of_actors);

    for (int i = 0; i < number_of_actors; ++i)
    {
        fscanf(fin, "%[^,],%[^,],%i,%i,%i/%i/%i,%[^,],%[^,],%[^\n]\n",
            actors[i].name, actors[i].surname, &actors[i].gender, &actors[i].height,
            &actors[i].birth_date.day, &actors[i].birth_date.month, &actors[i].birth_date.year, 
            actors[i].birth_address.country, actors[i].birth_address.region, actors[i].birth_address.city);
    }
    fclose(fin);
    return number_of_actors;
}


int read_movies_from_file(const char* filename, Movie* movies)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        fprintf(stdout, "Error. Can't open file %s!", filename);
        exit(1);
    }
    int number_of_movies;
    fscanf(fin, "%i", &number_of_movies);
    for (int i = 0; i < number_of_movies; ++i)
    {
        
        fscanf(fin, "%[^,],%i/%i/%i,%lf,%i,", movies[i].title, &movies[i].release_date.day, 
            &movies[i].release_date.month, &movies[i].release_date.year, &movies[i].rating, &movies[i].crew_size);
        for (int j = 0; j < movies[i].crew_size; ++j)
        {
            fscanf(fin, "%i", &movies[i].crew[j]);
        }
    }
    fclose(fin);
    return number_of_movies;
}


void read_database(MovieDatabase* pmd, const char* actors_file_name, const char* movies_file_name)
{
    pmd->number_of_actors = read_actors_from_file(actors_file_name, pmd->actors);
    pmd->number_of_movies = read_movies_from_file(movies_file_name, pmd->movies);
}


void print_actor(FILE* stream, const Actor* a)
{
    fprintf(stream, "%10s %15s. Height: %i cm. Birth date: %02i/%02i/%i. Birth Address: %s, %s, %s\n", a->name, a->surname,
           a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year, 
           a->birth_address.country, a->birth_address.region, a->birth_address.city);
}


void print_movie(FILE* stream, const Movie* a)
{
    fprintf(stream, "%20s. Rating: %.3lf. Release date: %02i/%02i/%i.\n", a->title, a->rating,
            a->release_date.day, a->release_date.month, a->release_date.year);
}


void print_movie_descriptive(FILE* stream, const MovieDatabase* pmd, int movie_id)
{
    if (movie_id < 0 || movie_id >= pmd->number_of_movies)
    {
        fprintf(stream, "Error. No movie with such id!\n");
        return;
    }
    print_movie(stdout, &pmd->movies[movie_id]);
    printf("Actors:\n");
    for (int i = 0; i < pmd->movies[movie_id].crew_size; ++i)
    {
        printf("\t");
        print_actor(stdout, &pmd->actors[pmd->movies[movie_id].crew[i]]);
    }
    printf("\n");
}


Movie find_best_movie_value(const MovieDatabase* pmd)
{
    int j = 0;

    for (int i = 1; i < pmd -> number_of_movies; ++i)
    {
        if (pmd->movies[j].rating < pmd->movies[i].rating)
            j = i;
    }

    return pmd->movies[j];
}


int find_best_movie_index(const MovieDatabase* pmd)
{
    int j = 0;

    for (int i = 1; i < pmd -> number_of_movies; ++i)
    {
        if (pmd->movies[j].rating < pmd->movies[i].rating)
            j = i;
    }

    return j;
}


const Movie* find_best_movie_pointer(const MovieDatabase* pmd)
{
    int j = 0;

    for (int i = 1; i < pmd -> number_of_movies; ++i)
    {
        if (pmd->movies[j].rating < pmd->movies[i].rating)
            j = i;
    }

    const Movie* p = &pmd->movies[j];

    return p;
}


void find_best_movie_argument(const MovieDatabase* pmd, Movie* p_best_movie)
{
    int j = 0;

    for (int i = 1; i < pmd -> number_of_movies; ++i)
    {
        if (pmd->movies[j].rating < pmd->movies[i].rating)
            j = i;
    }

    strcpy(p_best_movie->title, pmd->movies[j].title);

    p_best_movie->release_date = pmd->movies[j].release_date;

    p_best_movie->rating = pmd->movies[j].rating;

    p_best_movie->crew_size = pmd->movies[j].crew_size;

    for (int u = 0; u < p_best_movie->crew_size; ++u)
        p_best_movie->crew[u] = pmd->movies[j].crew[u];
}


void print_filmography(const MovieDatabase* pmd, char n[], char s[])
{
    int k = pmd->number_of_actors;

    for (int i = 0; i < k; ++i)
    {
        if ((strcmp(pmd->actors[i].surname, s) == 0) && (strcmp(pmd->actors[i].name, n) == 0))
        {
            k = i;
            break;
        }
    }

    int num = pmd->number_of_movies;

    for (int i = 0; i < num; ++i)
    {
        for (int j = 0; j < pmd->movies[i].crew_size; ++j)
        {
            if (pmd->movies[i].crew[j] == k)
                printf("%[^\0]", pmd->movies[i]);
        }
    }
}


Actor find_best_actor(const MovieDatabase* pmd)
{
    double summary[400] = {0};
    int num_of_films[400] = {0};

    for (int i = 0; i < pmd->number_of_movies; ++i)
    {
        for (int j = 0; j < pmd->movies[i].crew_size; ++j)
        {
            summary[pmd->movies[i].crew[j]] += pmd->movies[i].rating;
            ++num_of_films[pmd->movies[i].crew_size];
        }
    }

    double max = -1;
    int r = -2;

    for (int i = 0; i < pmd->number_of_actors; ++i)
    {
        if (summary[i] / num_of_films[i] > max)
            r = i;
    }

    Actor act = pmd->actors[r];

    return act;
}


void movie_of_the_year(const MovieDatabase* pmd, int premier)
{
    int num_of_films = 0;
    int films[400] = {0};

    for (int i = 0; i < pmd->number_of_movies; ++i)
    {
        if (pmd->movies[i].release_date.year == premier)
        {
            films[num_of_films] = i;
            ++num_of_films;
        }
    }


    float sup = FLT_MAX;
    int e;

    for (int i = 0; i < num_of_films; ++i)
    {
        float max = FLT_MIN;

        for (int j = 0; j < num_of_films; ++j)
        {
            if (max < pmd->movies[films[j]].rating && pmd->movies[films[j]].rating < sup)
            {
                max = pmd->movies[films[j]].rating;
                e = j;            
            }
        }
        printf("%[^\0]", pmd->movies[e]);
        sup = pmd->movies[e].rating;
    }

    return;
}



int main()
{
    MovieDatabase md;

    printf("%llu\n", sizeof(md));

    read_database(&md, "actors.csv", "movies.csv");

    const MovieDatabase* mov = &md;

    Movie best[100];
    Movie* b = best;

    while (1)
    {
        printf("Enter movie id (less than 4000):\n");

        int id;
        scanf("%i", &id);

        print_movie_descriptive(stdout, &md, id);

        find_best_movie_value(mov);
        find_best_movie_index(mov);
        find_best_movie_pointer(mov);
        find_best_movie_argument(mov, b);
        print_filmography(mov, "Ivan", "Nikulin");
    }
}