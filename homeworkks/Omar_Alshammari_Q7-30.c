#include <stdio.h>

#define PI 3.14159

void cal_circumference(double r);
void cal_area(double r);
void cal_volume(double r);

int main(void)
{
    printf("%s", "Enter radius\n");
    double radius; // variable to hold user's choice
    scanf("%lf", &radius);

    void (*f[3])(double) = {cal_circumference, cal_area, cal_volume};

    puts("Enter 0 to calaulate circumference");
    puts("Enter 1 to calaulate area");
    puts("Enter 2 to calaulate volume");
    size_t choice; // variable to hold user's choice
    scanf("%u", &choice);

    (*f[choice])(radius);                                
}

// circle circumference C=2πr
// cricle area A=π(r^2)
// sphere volume V = (4/3) * π * (r^3)

void cal_circumference(double r)
{
    printf("Calaulatring circumference for r = %.2lf\n", r);
    double circumference = 2 * PI * r;
    printf("circumference is: %.2lf\n", circumference);
}

void cal_area(double r)
{
    printf("Calaulatring area for r = %.2lf\n", r);
    double area = r * r * PI;
    printf("area is: %.2lf\n", area);
}

void cal_volume(double r)
{
    printf("Calaulatring volume for r = %.2lf\n", r);
    double volume = r * r * r * (4.0 / 3) * PI;
    printf("volume is: %.2lf\n", volume);
}