#import <stdio.h>

int main(void)
{
    int user_input;
    puts("Enter a nummber to Examin (-1) to finish");
    scanf("%d", &user_input);
    unsigned int counter = 0;
    while (user_input != EOF)
    {
        int is_prime = 1;

        for (int i = 2; i < user_input; i++) {
            if (user_input % i == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime && user_input > 0)
        {
            puts("Prime");
            counter++;
        } else {
            puts("Not a prime");
        }
        
        puts("Enter a nummber to Examin (-1) to finish");
        scanf("%d", &user_input);
    }    

    printf("total prime numbers are: %d\n", counter);
}