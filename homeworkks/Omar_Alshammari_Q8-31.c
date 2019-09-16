#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000

void print_letter_occurence(const char *sentence, size_t length);
void print_word_length_appearance(const char *sentence, size_t length);
void print_word_occurence(const char *sentence, size_t length);

int main(void)
{
    char user_input[MAX_TEXT_SIZE];
    memset(user_input, '\0', MAX_TEXT_SIZE);

    puts("Enter text to be analyzed: ");
    fgets(user_input, MAX_TEXT_SIZE - 1, stdin);

    puts("------------ Letter Occurence -------------");
    print_letter_occurence(user_input, strlen(user_input));

    puts("------------ Word Length Occurence -------------");
    print_word_length_appearance(user_input, strlen(user_input));

    // puts("------------ Word Occurence -------------");
    // print_word_occurence(user_input, strlen(user_input)).
}

void print_letter_occurence(const char *sentence, size_t length)
{
    int all_letters[26] = {0};
    for (size_t i = 0; i < length; i++)
    {
        if ((toupper(sentence[i]) >= 'A') && (toupper(sentence[i]) <= 'Z'))
        {
            ++all_letters[(toupper(sentence[i]) - 'A')];
        }
    }
    puts("Letter     Occurences");
    for (size_t i = 0; i < 26; i++)
    {
        printf("%6c %5d\n", i + 'A', all_letters[i]);
    }

    puts("");
    
}

void print_word_length_appearance(const char *sentence, size_t length)
{
    int word_lengths[10] = {0};
    size_t count = 0;
    while (1)
    {
        count = strcspn(sentence, " ");
        printf("count is: %d\n", count);
        if (count != 0)
        {
            ++word_lengths[count];
            sentence += ++count;
        } else {
            break;
        }
    }
    puts("Word length     Occurences");
    for (size_t i = 1; i < 10; i++)
    {
        printf("%11d %5d\n", i , word_lengths[i]);
    }
    
}

void print_word_occurence(const char *sentence, size_t length)
{
}