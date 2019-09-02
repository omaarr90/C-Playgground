#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{ 
    char test[5];
    puts("Enter 4 digits hex");

    scanf("%4s", test);

    test[4] = '\0';

    int hex_value = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (isxdigit(test[i]) && isdigit(test[i]))
        {
            hex_value += (test[i] - 48) * pow(16, 3 - i);
        } else if (isxdigit(toupper(test[i]))) {
            hex_value += (toupper(test[i]) - 'A' + 10) * pow(16, 3 - i);
        } else {
            hex_value = -1;
            break;
        }
        
    }
    
    if (hex_value != -1) {
        puts("It's a hex value");
        printf("The value is: %d\n", hex_value);

    }
    
}