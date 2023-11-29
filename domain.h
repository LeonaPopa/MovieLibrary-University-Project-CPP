
#include <string>
#include <fstream>
#pragma  once
typedef std::string string;

class Movie{

private:
    string genre;
    int year_of_release{};
    int number_of_likes{};
    string trailer_url;
    string title;
public:
    void setGenre(const string &genre);
    void setYearOfRelease(int yearOfRelease);
    void setTitle(const string &title);
public:
    friend std::ostream& operator<<(std::ostream& os, Movie& movie);
    friend std::ifstream & operator>>(std::ifstream & os, Movie& movie);
    bool operator==(const Movie& other);
    Movie(string , string , int, int, string);
    Movie();
    string get_title();
    string get_genre();
    int get_year_of_release() const;
    int get_number_of_likes() const;
    string get_trailer_url();
    void set_number_of_likes(int);
    void set_trailer_url(string);
};
