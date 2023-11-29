
#include "../../Assignment8/header files/repository.h"
#include <string>
#pragma  once

class MovieWatchlist:public MovieRepository{
private:
    std::string format;
    std::vector<Movie*> movie_watchlist;
public:
    void setFormat(const string &format);
    void add_movie_to_watchlist(Movie* new_movie);
    void write_to_file();
    void open_file() const;
    bool delete_movie_from_watchlist(const string& title, const string& genre, int year_of_release);
    std::vector<Movie*> getMovies() const {return movie_watchlist;}
};
