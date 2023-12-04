#include <stdio.h>
#include <stdlib.h>

int get_calibration_value(char *str)
{
    char digits[2] = {0};
    char c;
    for (char *ptr = str; (c = *ptr) != '\0'; ptr++)
    {
        if (c >= '0' && c <= '9')
        {
            if (digits[0] == 0)
                digits[0] = c;
            else
            {
                digits[1] = c;
            }
        }
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
