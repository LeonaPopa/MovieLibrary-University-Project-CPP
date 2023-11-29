//
// Created by Leona on 4/13/2023.
//

#include "../../A8/header files/domain.h"
#include <utility>
#include <iostream>


Movie::Movie(string title, string genre, int year_of_release, int number_of_likes, string trailer_url)
{
    this->title = std::move(title);
    this->genre = std::move(genre);
    this->year_of_release = year_of_release;
    this->number_of_likes = number_of_likes;
    this->trailer_url = std::move(trailer_url);
}

string Movie::get_title()
{
    return this->title;
}

string Movie::get_genre()
{
    return this->genre;
}

int Movie::get_year_of_release() const
{
    return this->year_of_release;
}

int Movie::get_number_of_likes() const
{
    return this->number_of_likes;
}

string Movie::get_trailer_url()
{
    return this->trailer_url;
}

void Movie::set_number_of_likes(int new_number_of_likes)
{
    this->number_of_likes = new_number_of_likes;
}

void Movie::set_trailer_url(string new_trailer_url)
{
    this->trailer_url = std::move(new_trailer_url);
}

std::ostream& operator<<(std::ostream& os, Movie &movie) {
    os << movie.get_title() << "," << movie.get_genre() << ","<< movie.get_year_of_release() << "," << movie.get_number_of_likes() << ","<< movie.get_trailer_url() << std::endl;
    return os;
}

bool Movie::operator==(const Movie &other) {
    return title==other.title && genre == other.genre && year_of_release == other.year_of_release && trailer_url == other.trailer_url;
}

std::ifstream &operator>>(std::ifstream &os, Movie &movie) {
    std::string title, genre, trailer,y,l;
    int year, likes;
    std::getline(os, title, ',');
    std::getline(os, genre, ',');
    std::getline(os, y, ',');
    std::getline(os, l, ',');
    std::getline(os, trailer);
    year = stoi(y);
    likes= stoi(l);
    movie.setTitle(title);
    movie.setGenre(genre);
    movie.setYearOfRelease(year);
    movie.set_number_of_likes(likes);
    movie.set_trailer_url(trailer);
    return os;
}

Movie::Movie() {
    this->title = "";
    this->genre = "";
    this->year_of_release = 0;
    this->number_of_likes = 0;
    this->trailer_url = "";
}

void Movie::setGenre(const string &Genre) {
    Movie::genre = Genre;
}

void Movie::setYearOfRelease(int yearOfRelease) {
    year_of_release = yearOfRelease;
}

void Movie::setTitle(const string &Title) {
    Movie::title = Title;
}
