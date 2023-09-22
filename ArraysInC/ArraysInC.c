// Online C compiler to run C program online
#include <stdbool.h>
#include <stdio.h>

void swap(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void bubbleSort(double arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

int main() {
    
    const int numOfCompetitors = 5;
    double competitorScores[numOfCompetitors];
    
    printf("%d\n", sizeof(competitorScores));
    printf("%d\n", sizeof(competitorScores[0]));
    printf("%d\n", sizeof(competitorScores)/sizeof(competitorScores[0]));
    
    for (int ii = 0; ii < sizeof(competitorScores)/sizeof(competitorScores[0]); ii++){
        printf("%d", ii);
        printf("Enter the score of competitor %d\n", ii+1);
        while(scanf("%lf", &competitorScores[ii]) != 1){
            printf("invalid input, try again:\n");
            while ((getchar()) != '\n');
        }
    }
    
    printf("here?");
    int N = sizeof(competitorScores) / sizeof(competitorScores[0]);
    bubbleSort(competitorScores, N);
    
    for(int ii = 0; ii < sizeof(competitorScores)/sizeof(competitorScores[0]); ii++){
        printf("%lf", competitorScores[ii]);
    }
}

