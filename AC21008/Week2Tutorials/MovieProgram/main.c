#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movie.h"

int main(){

    movie my_film;
    initialise_movie(&my_film);

    display_movie_details(&my_film);

    ask_for_movie_details(&my_film);

    display_movie_details(&my_film);

    movie* m = NULL;
    m = &my_film;

    printf("Memory address of the 'my_film' variable is %p.\n", m);

    strncpy((*m).title, "Noice\n", 100);
    (*m).runtime = 69;
    m->review_score = 42;

    display_movie_details(m);

    movie films[3];

    // for(int ii = 0; ii < 3; ii++){
    //     ask_for_movie_details(&films[ii]);
    // }

    display_movies(films, 3);

    movie* dynamic_movie = NULL;
    dynamic_movie = (movie*)malloc(sizeof(movie));

    if(dynamic_movie == NULL){
        printf("OOPSIE, NO RAM");
        return 0;
    }

    ask_for_movie_details(dynamic_movie);
    display_movie_details(dynamic_movie);

    free(dynamic_movie);

    movie* film_array = NULL;
    film_array = (movie*)malloc(sizeof(movie) * 3);

    if(film_array == NULL){
        printf("OOPSIE, NO RAM");
        return 0;
    }

    for(int ii = 0; ii < 3; ii++){
        initialise_movie(&film_array[ii]);
    }
    display_movies(film_array, 3);

    free(film_array);

    return 0;
}