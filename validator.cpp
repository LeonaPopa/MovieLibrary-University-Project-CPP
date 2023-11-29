//
// Created by Leona on 4/21/2023.
//

#include "../../Assignment8/header files/validator.h"

#include <string>
#include <cstring>

bool MovieValidator::is_valid_title(const std::string& title)
{
    return !title.empty();
}
 bool MovieValidator::is_valid_genre(const std::string& genre)
{
    return !genre.empty();
}
bool MovieValidator::is_valid_year(int year)
{
    return year > 0 && year <= 2023;
}
bool MovieValidator::is_valid_likes(int likes)
{
    return likes >= 0;
}
bool MovieValidator::is_valid_trailer(const std::string& trailer)
{
    return !trailer.empty() && trailer.find("youtube.com") != std::string::npos;
}
bool MovieValidator::is_number(char* str)
{
    if (strlen(str) == 0)
        return false;
    int length = (int)strlen(str);
    for (int i = 0; i < length; i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}