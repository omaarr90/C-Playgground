// What does this function do?
// ex07_19.c
// What does this program do?
#include <stdio.h>
#define SIZE 80

void mystery1(char *s1, const char *s2); // prototype 7

int main(void) {
    char string1[SIZE]; // create char array char 
    char string2[SIZE]; // create char array
    puts("Enter two strings: "); 
    scanf("%79s%79s" , string1, string2); 
    mystery1(string1, string2); 
    printf("%s", string1);
}

void mystery1(char *s1, const char *s2) {
    while (*s1 != '\0') { 
        ++s1;
    }

    for (; *s1 = *s2; ++s1, ++s2) { ; // empty statement
    } 
}
