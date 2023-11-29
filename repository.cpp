//
// Created by Leona on 4/13/2023.
//


#include <iostream>
#include <utility>
#include "../header files/repository.h"

void MovieRepository::add_movie_to_repo(Movie *new_movie)
{
    this->movie_repository.push_back(new_movie);
    std::ofstream f("movie_repository.csv");
    if (!f)
    {
        std::cout << "Unable to open file\n";
        throw MovieException("");
    }
    for (auto & it : this->movie_repository) {
        f << *it;
    }
    f.close();
}

bool MovieRepository::remove_movie(const string& title, const string& genre, int year_of_release)
{
    bool ok = false;
    std::ofstream f("movie_repository.csv");
    if (!f) {
        throw MovieException("Unable to open file!\n");
    }
    f.clear();
    for (auto it = this->movie_repository.begin(); it != this->movie_repository.end(); it++)
    {
        if ((*it)->get_title() == title && (*it)->get_genre() == genre && (*it)->get_year_of_release() == year_of_release)
        {
            this->movie_repository.erase(it);
            ok = true;
            break;
        }
    }
    for (auto & it : this->movie_repository) {
        f << *it;
    }
    f.close();
    return ok;
}

Movie *MovieRepository::get_movie(int index) const
{
    if (index < 0 || index > movie_repository.size())
        throw MovieException("");
    return this->movie_repository[index];
}

int MovieRepository::get_length() const
{
    return (int)this->movie_repository.size();
}

Movie *MovieRepository::get_movie(const string& title, const string& genre, int year_of_release)
{
    for (auto & it : this->movie_repository)
    {
        if ( it->get_title() == title && it->get_genre() == genre && it->get_year_of_release() == year_of_release) {
            return it;
        }
    }
    throw MovieException("");
}

void MovieRepository::load_from_file() {
    std::ifstream f;
    f.open("movie_repository.csv",std::ios_base::in);
    if (!f) {
        std::cout << "Unable to open file\n";
        throw MovieException("");
    }
    while (f.good()) {
        std::string title, genre, trailer,y,l;
        int year, likes;
        std::getline(f, title, ',');
        std::getline(f, genre, ',');
        std::getline(f, y, ',');
        std::getline(f, l, ',');
        std::getline(f, trailer);
        year = stoi(y);
        likes= stoi(l);
        auto movie = new Movie(title, genre, year, likes, trailer);
        this->movie_repository.push_back(movie);
    }
    f.close();
}

void MovieRepository::update_number_of_likes(Movie *movie, int new_nr_of_likes) {
    std::ofstream f("movie_repository.csv");
    if (!f) {
        std::cout << "Unable to open file\n";
    }
    f.clear();
    movie->set_number_of_likes(new_nr_of_likes);
    for (auto & it : this->movie_repository)
    {
        f << *it ;
    }
    f.close();
}

void MovieRepository::update_trailer_url(Movie *movie, string new_trailer_url) {
    std::ofstream f("movie_repository.csv");
    if (!f) {
        std::cout << "Unable to open file\n";
    }
    f.clear();
    movie->set_trailer_url(std::move(new_trailer_url));
    for (auto & it : this->movie_repository)
    {
        f << *it ;
    }
    f.close();
}
