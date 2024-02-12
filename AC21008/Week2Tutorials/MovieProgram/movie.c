#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

void initialise_movie(movie* Movie){
    Movie->runtime = 0;
    Movie->review_score = 0;
    strcpy(Movie->title, "<Undefined>\n");
}

void display_movie_details(movie* Movie){
    printf("Movie: %sruntime: %d minutes\nreview score: %d/100\n\n", Movie->title, Movie->runtime, (*Movie).review_score);
}

void ask_for_movie_details(movie* Movie){
    printf("please enter the name of a film:\n");

    char *title = (char *)malloc(10);
    size_t size = 10;
    getline(&title, &size, stdin);
    strncpy(Movie->title, title, 99);
    
    printf("please enter the runtime of the film in minutes:\n");
    scanf("%d", &(*Movie).runtime);
    printf("please enter the review score of the film out of 100:\n");
    scanf("%d", &(*Movie).review_score);
    while(getchar() != '\n');
}

void display_movies(movie array[], int size){
    for (int ii = 0; ii < size; ii++){
        display_movie_details(&array[ii]);
    }
}