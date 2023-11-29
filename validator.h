#pragma  once
#include <string>

class MovieValidator{
public:
    static bool is_valid_title(const std::string& title);
    static bool is_valid_genre(const std::string& genre);
    static bool is_valid_year(int year);
    static bool is_valid_likes(int likes);
    static bool is_valid_trailer(const std::string& trailer);
    static bool is_number(char* str);
};
