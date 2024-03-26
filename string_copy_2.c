#include <stdio.h>

void copyString(char *, char *, int, int);

int main()
{
    char str1[100], str2[100];
    int index, len;

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    for (len = 0; str1[len] != '\0' && str1[len] != '\n'; len++);

    copyString(str1, str2, 0, len);

    str2[len] = '\0';

    printf("The copied string is: %s", str2);

    return 0;	
}
void copyString(char *str1, char *str2, int index, int len)
{
    if (index >= len)
        return;

    str2[index] = str1[index];

    copyString(str1, str2, index + 1, len);
}
