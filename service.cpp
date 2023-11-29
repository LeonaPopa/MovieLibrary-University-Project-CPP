//
// Created by Leona on 4/13/2023.
//

#include <utility>
#include <iostream>

#include "../../Assignment8/header files/service.h"


void MovieService::add(const string& title, const string& genre, int year_of_release, int number_of_likes, string trailer_url) {
    Movie *p;
    if (year_of_release <= 0)
        throw MovieException("Year of release is negative!");
    auto *new_movie = new Movie{title, genre, year_of_release, number_of_likes, std::move(trailer_url)};
    for (auto m: movie_service.getMovies())
        if(m==new_movie)
            throw MovieException("Movie already exists!\n");
    this->movie_service.add_movie_to_repo(new_movie);
}

bool MovieService::remove_service(const string& title, const string& genre, int year_of_release) {
    bool ok = false;
    if (year_of_release < 0)
        return false;
    ok = this->movie_service.remove_movie(title, genre, year_of_release);
    return ok;
}

void MovieService::update_number_of_likes(Movie * movie, int new_nr_of_likes) {
    try {
        this->movie_service.update_number_of_likes(movie, new_nr_of_likes);
    }catch(const MovieException& ex){
        throw MovieException("couldn't update!\n");
    }
}

void MovieService::update_trailer_url(Movie * movie, string new_trailer_url) {
    try {
        this->movie_service.update_trailer_url(movie, std::move(new_trailer_url));
    }catch(const MovieException&ex){
        throw MovieException("couldn't update!\n");
    }
}

int MovieService::get_nr_movies() const {
    return this->movie_service.get_length();
}

Movie* MovieService::get_movie(int index) const{
    if (index < 0)
        return nullptr;
    return this->movie_service.get_movie(index);
}

Movie* MovieService::get_movie(const string& title, const string& genre, int year_of_release)
{
    if (year_of_release <= 0)
        return nullptr;

    return this->movie_service.get_movie(title, genre, year_of_release);
}

std::vector<Movie*> MovieService::getAllMovies() {
    return this->movie_service.getMovies();
}

MovieService::MovieService() {
    movie_service.load_from_file();
}
