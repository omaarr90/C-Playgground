#include <stdio.h>

#define FREQ_SIZE 52
#define A_CAPITAL_VALUE 'A'
#define Z_CAPITAL_VALUE 'Z'
#define A_SMALL_VALUE 'a'
#define Z_SMALL_VALUE 'z'
#define A_SMALL_OFFSET ('a' - 'Z' - 1)

void print_frequncies(const int b[], size_t index);

int main(void)
{
    int letter_frequencies[FREQ_SIZE] = {0};
    char ch;
    puts("please enter a line of text terminated by EOF");
    ch = getchar();
    while (ch != EOF)
    {
        if ((ch >= A_CAPITAL_VALUE && ch <= Z_CAPITAL_VALUE)) {
            ++letter_frequencies[ch - A_CAPITAL_VALUE];
        }
        else if ((ch >= A_SMALL_VALUE && ch <= Z_SMALL_VALUE)) {
            ++letter_frequencies[ch - A_CAPITAL_VALUE - A_SMALL_OFFSET];
        }
        ch = getchar();
    }
    printf("\n%6s %15s\n", "Letter", "Frequency");
    print_frequncies(letter_frequencies, 0);
}

void print_frequncies(const int b[], size_t index)
{
    if(index == FREQ_SIZE) {
        return; //nothing to print
    }
    const char lineformat = ((index % 3) == 0) ? '\n' : '\t';
    int offset = (index + A_CAPITAL_VALUE > Z_CAPITAL_VALUE) ? A_SMALL_OFFSET : 0;
    printf("%6c%16d\n", (index + A_CAPITAL_VALUE + offset), b[index]);
    print_frequncies(b, index + 1);
}