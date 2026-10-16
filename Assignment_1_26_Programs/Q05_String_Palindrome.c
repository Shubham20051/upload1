#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[1000];
    size_t left, right;
    int palindrome = 1;
    printf("STRING PALINDROME CHECK\nEnter a string: ");
    if (!fgets(str, sizeof str, stdin)) {
        printf("Input error.\n");
        return 1;
    }
    if (strchr(str, '\n') == NULL && !feof(stdin)) {
        printf("Input too long. Maximum length is 998 characters.\n");
        return 1;
    }
    str[strcspn(str, "\n")] = '\0';
    left = 0;
    right = strlen(str);
    if (right > 0)
        right--;
    while (left < right) {
        while (left < right && isspace((unsigned char)str[left]))
            left++;
        while (left < right && isspace((unsigned char)str[right]))
            right--;
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            palindrome = 0;
            break;
        }
        left++;
        if (right > 0)
            right--;
    }
    if (palindrome)
        printf("The string is a palindrome (ignoring case and spaces).\n");
    else
        printf("The string is not a palindrome.\n");
    return 0;
}
