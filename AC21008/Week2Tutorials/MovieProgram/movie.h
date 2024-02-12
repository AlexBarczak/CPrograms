#ifndef MOVIE_HEADER
#define MOVIE_HEADER

typedef struct movie_details{
    int runtime;
    int review_score;
    char title[100];
} movie;

void initialise_movie(movie* Movie);
void display_movie_details(movie* Movie);
void ask_for_movie_details(movie* Movie);
void display_movies(movie array[], int size);

#endif