
#include "../../A8/header files/domain.h"
#include "../../Assignment8/header files/exeptions.h"
#include <vector>
#include <fstream>

#pragma once

class MovieRepository{
public:
    void add_movie_to_repo(Movie*);
    Movie* get_movie(int) const;
    Movie* get_movie(const string&, const string&, int);
    virtual int get_length() const;
    bool remove_movie(const string&, const string&, int);
    std::vector<Movie*> movie_repository;
    void load_from_file() ;
    void update_number_of_likes(Movie * movie, int new_nr_of_likes);
    void update_trailer_url(Movie * movie, string new_trailer_url);
    virtual std::vector<Movie*> getMovies() const {return movie_repository;}
};
