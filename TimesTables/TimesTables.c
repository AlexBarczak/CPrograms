#include <stdio.h>

int main(void) {
    int multTable = -1;
    int numOfRepeats = 0;

    printf("Which multiplication table would you like to display?\n");
    while (scanf("%d", &multTable) != 1) {
        printf("invalid input, try again:\n");
        while ((getchar()) != '\n');
    }

    printf("How far would you like to see this times table?\n");
    while (scanf("%d", &numOfRepeats) != 1) {
        printf("invalid input, try again:\n");
        while ((getchar()) != '\n');
    }

    printf("you want to see the %d times table up to %d * %d\n", multTable, multTable, numOfRepeats);

    for (int ii = 1; ii < numOfRepeats; ii++) {
        printf("%d * %d = %d\n", multTable, ii, multTable * ii);
    }

}