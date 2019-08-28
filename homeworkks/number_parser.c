#import <stdio.h>
#import <stdbool.h>

int main (void)
{
    long total = 0;
    long current_number = 0;
    char current_char;
    bool is_still_valid_number = true;
    bool is_negative = false;
    bool can_add_negativ_sign = true;
    puts("Please enter a list of numbers (EOF) to terminate");
    while ((current_char = getchar()) != EOF)
    {
        switch (current_char)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            can_add_negativ_sign = false;
            if (!is_still_valid_number) {
                break;
            }
            if (current_number != 0)
            {
                current_number *= 10;
            }
            
            current_number += (current_char - 48);            
            break;
        case '-':
            if (can_add_negativ_sign)
            {
                is_negative = !is_negative;
            } else {
                current_number = 0;
                is_still_valid_number = false;
            }
            break;           
        case '\n':
        case '\t':
        case ' ':
            if (is_negative) {
                current_number *= -1;
            }
            total += current_number;
            is_still_valid_number = true;
            is_negative = false;
            can_add_negativ_sign = true;
            current_number = 0;
            break;
        default:
            current_number = 0;
            is_still_valid_number = false;
            break;
        }
    }
    printf("total is: %ld\n", total);
}