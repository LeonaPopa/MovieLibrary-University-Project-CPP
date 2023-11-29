//
// Created by Leona on 4/13/2023.
//

#include "../../Assignment8/header files/repository.h"
#pragma  once

class MovieService{
public:
    MovieService();
    void add(const string& , const string&, int, int, string);
    void update_number_of_likes(Movie*, int);
    void update_trailer_url(Movie*, string);
    int get_nr_movies() const;
    bool remove_service(const string&, const string&, int);
    Movie* get_movie(int) const;
    Movie* get_movie(const string&, const string&, int);
    MovieRepository movie_service{};
    std::vector<Movie*> getAllMovies();
};