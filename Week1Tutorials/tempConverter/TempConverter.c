#include <stdio.h>

double GetCelsius(double fahrenheitTemp){
    return (fahrenheitTemp - 32.0) * (5.0/9.0);
}

int main(void){
    double fTemp;
    
    printf("enter a temperature in fahrenheit: \n");
    scanf("%lf", &fTemp);

    double celsiusTemp = GetCelsius(fTemp);
    printf("%lf\n\n", (fTemp - 32.0) * (5.0/9.0));

    printf("%lf degree Fahrenheit is %lf degrees Celsius\n", fTemp, celsiusTemp);
    return 0;
}