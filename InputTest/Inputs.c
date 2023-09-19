#include <stdio.h>

int main(){
    
    char favouriteColour[20];
    int age;

    printf("what is your age?\n");
    scanf("%d", &age);

    printf("what is your favourite colour?\n");
    scanf("%s", favouriteColour);

    printf("You are %d years old and your favourite colour is %s\n", age, favouriteColour);

}