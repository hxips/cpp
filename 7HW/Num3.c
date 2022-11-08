#include <stdlib.h>
#include <stdio.h>
#include <string.h>



char** get_test_strings()
{
    char** p = (char**)malloc(sizeof(char*) * 4);

    for (int i = 0; i < 3; ++i)
        p[i] = (char*)malloc(sizeof(char) * 128);

    strcpy(p[0], "Mouse");
    strcpy(p[1], "Cat");
    strcpy(p[2], "Elephant");
    p[3] = NULL;

    return p;
}


void print_strings(FILE* stream, char** string_array)
{
    int i = 0;

    while (string_array[i] != NULL)
    {
        fprintf(stream, "%s\n", string_array[i]);
        ++i;
    }

    return;
}


char** load_lines(const char* filename)
{
    FILE* f = fopen(filename, "r");

    int strings = 1;

    char sim;

    do{
        sim = fgetc(f);

        if (sim == '\n')
            ++strings;

    } while(sim != EOF);

    char** p = (char**)malloc(sizeof(char*) * (strings + 1));


    fseek(f, 0, SEEK_SET);


    int* num = (int*)malloc(strings);

    for (int i = 0; i < strings; ++i)
    {
        int k = -1;

        do{
            sim = fgetc(f);

            ++k;

        } while(sim != EOF && sim != '\n');

        num[i] = k;
    }

    for (int i = 0; i < strings; ++i)
        p[i] = (char*)malloc((num[i] + 1) * sizeof(char));

    free(num);


    fseek(f, 0, SEEK_SET);


    for (int i = 0; i < strings; ++i)
        fscanf(f, "%s", p[i]);

    fclose(f);

    p[strings] = NULL;

    return p;
}


void destroy_strings(char*** p_string_array)
{
    int i = 0;

    while (*p_string_array[i] != NULL)
    {
        free(*p_string_array[i]);
        ++i;
    }

    free(*p_string_array);

    *p_string_array = NULL;

    return;
}


void sort_strings(char** words)
{
    int k = 1;

    while (words[k] != NULL)
        ++k;
    
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k - j - 1; ++j)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    return;
}



int main()
{
    char** test = get_test_strings();
    print_strings(stdout, test);
    sort_strings(test);
    print_strings(stdout, test);
    destroy_strings(&test)
}
