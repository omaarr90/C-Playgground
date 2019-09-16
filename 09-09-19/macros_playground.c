#include <stdio.h>
#include <assert.h>

#define DEBUG 0
#define PI 3.14
#define ASSERT_TRUE(x)                                                          \
                            if (!(x)) {                                         \
                                printf("Assertionn Failed: " #x "\n");          \
                                return 0;                                       \
                            } else {                                            \
                                printf("Assertionn Succeeded: " #x "\n");       \
                            }                                           
                        

#define CIRCLE_AREA(x) (PI * (x) * (x))
#define AREA_SEQUARED(x) ((CIRCLE_AREA((x))) * (CIRCLE_AREA((x))))

int main(void)
{
    #if !__STDC__ 
        return 0;
    #endif
    int a = 5, b = 5;
    ASSERT_TRUE(a == b);

    double area = CIRCLE_AREA(3);
    double area_squared = AREA_SEQUARED(3);
    #ifdef DEBUG 
        printf("circle area is: %lf\n", area);
        printf("circle area sequared is: %lf\n", area_squared);
    #endif
}