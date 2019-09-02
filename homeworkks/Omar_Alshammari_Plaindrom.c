/*
(Palindromes) 
A palindrome is a string that’s spelled the same way forward and backward. 
Some examples of palindromes are: “radar,” “able was i ere i saw elba,” and, 
if you ignore blanks, “a man a plan a canal panama.” 
Write a recursive function testPalindrome that returns 1 if the string stored in the array is a palindrome and 0 otherwise. 
The function should ignore spaces and punctu- ation in the string.

*/

#include <stdio.h>
#include <ctype.h>

size_t testPalindrome(const char string[], int start, int end);

int main(void)
{
    int length;
    puts("Please enter the length of the word you want to test:");
    scanf("%d", &length);

    char string[length + 1];
    puts("Please enter the word you want to test:");
    scanf("%s", string);

    printf("user word (%s)\n", string);

    if (testPalindrome(string, 0, length))
    {
        puts("\nIt's a plaindrome");
    } else {
        puts("\nIt's not a plaindrome");
    }
    
}

size_t testPalindrome(const char string[], int start, int end)
{
    if (start >= end)
    {
        return 1; // it's plaindrome
    }
    puts("\n\n");
    printf("Start: (%d)\n", start);
    printf("End: (%d)\n", end);
    printf("String[start]: (%c)\n", string[start]);
    printf("String[end]: (%c)\n", string[end]);

    char cap_start = toupper(string[start]);
    char cap_end = toupper(string[end]);

    if (cap_start < 'A' || cap_start > 'Z')
    {
        return testPalindrome(string, start + 1, end); // Ignore non-alphbatic
    }

    if (cap_end < 'A' || cap_end > 'Z')
    {
        return testPalindrome(string, start, end - 1); // Ignore non-alphbatic
    }
    
    if (cap_start != cap_end)
    {
        return 0; // not a plaindrome
    }

    return testPalindrome(string, start + 1, end - 1);
    
}