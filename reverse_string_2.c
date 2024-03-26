#include <stdio.h>

void reverse(char *str, int index, int len)
{
    if (index >= len)
        return;
    char temp = str[index];
    str[index] = str[len - index - 1];
    str[len - index - 1] = temp;

 
    reverse(str, index + 1, len);
}	

int main()
{
    char str[100];

 
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    reverse(str, 0, len);


    printf("Reversed string: %s\n", str);

    return 0;
}
