#include <limits.h>

void bin(unsigned n) 
{ 
    /* step 1 */
    if (n > 1) 
        bin(n/2); 
  
    /* step 2 */
    printf("%d", n % 2); 
} 
  
int main(void) 
{ 
    bin(INT_MAX); 
    printf("\n"); 
    bin(4); 
}
