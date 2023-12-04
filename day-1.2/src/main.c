#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word
{
    char *name;
    char value;
    int len;
};

struct word words[9] = {
    {"one", '1', 3}, {"two", '2', 3},   {"three", '3', 5}, {"four", '4', 4}, {"five", '5', 4},
    {"six", '6', 3}, {"seven", '7', 5}, {"eight", '8', 5}, {"nine", '9', 4},
};

int get_calibration_value(char *str)
{
    char digits[2] = {0};
    char c, x = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        c = str[i];
        if (c >= '0' && c <= '9')
            x = c;
        else
        {
            for (int j = 0; j < 9; j++)
            {
                struct word w = words[j];
                char buffer[w.len + 1];
                memcpy((void *)&buffer, &str[i], w.len);
                buffer[w.len] = '\0';
                if (!strcmp(buffer, w.name))
                {
                    x = w.value;
                    i += w.len - 1;
                    break;
                }
            }
        }
        if (digits[0] == 0)
            digits[0] = x;
        else
            digits[1] = x;
    }
    if (digits[1] == 0)
        digits[1] = digits[0];
    return atoi(digits);
}

int main()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int sum = 0;

    fp = fopen("calibration.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while ((nread = getline(&line, &len, fp)) != -1)
    {
        sum += get_calibration_value(line);
    }

    printf("%d\n", sum);

    free(line);
    fclose(fp);
    return EXIT_SUCCESS;
}
