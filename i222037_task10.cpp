#include <iostream>
#include <string>
using namespace std;
struct Movie {
    string title;
    string director;
    int releaseYear;
    double rating;
};

const int MAX_MOVIES = 100; 
void addMovie(Movie database[], int& numMovies, const Movie& movie) {
    if (numMovies < MAX_MOVIES) {
        database[numMovies++] = movie;
    } else {
        cout << "Database is full. Cannot add more movies." << endl;
    }
}
Movie searchMovie(const Movie database[], int numMovies, const string& title) {
    for (int i = 0; i < numMovies; ++i) {
        if (database[i].title == title) {
            return database[i];
        }
    }
    return Movie{"", "", 0, 0.0};
}
void displayMovie(const Movie& movie) {
    if (!movie.title.empty()) {
        cout << "Title: " << movie.title << endl;
        cout << "Director: " << movie.director << endl;
        cout << "Release Year: " << movie.releaseYear << endl;
        cout << "Rating: " << movie.rating << endl;
    } else {
       cout << "Movie not found." << endl;
    }
}

int main() {
    Movie database[MAX_MOVIES];
    int numMovies = 0;
    addMovie(database, numMovies, {"Movie 1", "Director 1", 2020, 8.0});
    addMovie(database, numMovies, {"Movie 2", "Director 2", 2019, 7.5});
    string searchTitle = "Movie 1";
    Movie foundMovie = searchMovie(database, numMovies, searchTitle);
cout << "Movie Information:" << std::endl;
    displayMovie(foundMovie);

    return 0;
}

