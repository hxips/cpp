#include <stdlib.h>
#include <stdio.h>
#include <string.h>



char** load_lines(const char* filename)
{
    FILE* file = fopen(filename, "r");

    int lines = 1;

    while (1)
    {
        int sim = fgetc(file);

        if (sim == EOF)
            break;

        else if (sim == '\n')
            ++lines;
    }

    char** res = (char**)malloc((lines + 1) * sizeof(char*));

    fseek(file, 0, SEEK_SET);

    int* simbs = (int*)malloc(lines * sizeof(int));

    int count = 0;
    int string = 0;

    while (1)
    {
        int sim = fgetc(file);

        if (sim == EOF)
        {
            simbs[string] = count;
            break;
        }
            
        else if (sim == '\n')
        {
            simbs[string] = count;
            count = 0;
            ++string;
        }
            
        else
            ++count;
        
    }

    for (int i = 0; i < string; ++i)
        res[i] = (char*)malloc((simbs[i] + 1) * sizeof(char));
    
    free(simbs);

    fseek(file, 0, SEEK_SET);

    string = 0;
    count = 0;

    while (1)
    {
        int sim = fgetc(file);
    
        if (sim == EOF)
        {
            res[string][count] = '\0';
            ++string;
            break;
        }
            
        else if (sim == '\n')
        {
            res[string][count] = '\0';
            count = 0;
            ++string;
        }
            
        else
        {
            res[string][count] = sim;
            ++count;
        }
    }

    fclose(file);

    res[string] = NULL;

    return res;
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



int main(int argc, char** argv)
{
    char** lines = load_lines(argv[1]);

    sort_strings(lines);

    FILE* f = fopen(argv[2], "w");

    int i = 0;

    while (lines[i] != NULL)
    {
        int j = 0;

        while (lines[i][j] != '\0')
        {
            fputc(lines[i][j], f);

            ++j;
        }

        fputc('\n', f);

        ++i;
    }

    fclose(f);
    
    destroy_strings(lines);
}