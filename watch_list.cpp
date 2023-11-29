//
// Created by Leona on 5/2/2023.
//

#include <fstream>
#include <stdexcept>
#include "../header files/watch_list.h"


void MovieWatchlist::add_movie_to_watchlist(Movie* new_movie) {
    this->movie_watchlist.push_back(new_movie);
    this->write_to_file();
}

void MovieWatchlist::write_to_file() {
    std::ofstream f("movie_watchlist." + this->format);
    if (!f) {
        throw MovieException("Unable to open file");
    }
    if(this->format == "html") {
        f << "<!DOCTYPE html>" << std::endl;
        f<< "<html>\n<head>\n\t<title>MovieWatchlist</title>\n<body>\n<table border=\"1\">\n<tr><th>Title</th><th>Genre</th><th>Year</th><th>Likes</th><th>Trailer</th></tr>";
    }
    for (auto& it : this->movie_watchlist) {
        if (this->format == "csv") {
            f << it->get_title() << "," << it->get_genre() << ","
              << it->get_year_of_release() << "," << it->get_number_of_likes() << ","
              << it->get_trailer_url() << "\n";
        } else if (this->format == "html") {
            f << "<tr><td>" << it->get_title() << "</td><td>" << it->get_genre() << "</td><td>" << it->get_year_of_release() << "</td><td>" << it->get_number_of_likes() << "</td><td><a href=\"" << it->get_trailer_url() << "\">Watch Trailer</a></td></tr>";
        } else {
            throw MovieException("Invalid format");
        }
    }
    if(this->format == "html")
        f << "</table></body></html>";

    f.close();
}

void MovieWatchlist::open_file() const {
    std::string command;
    if (this->format == "csv") {
        command = "notepad.exe movie_watchlist.csv";
    } else if (this->format == "html") {
        command = "start movie_watchlist.html";
    } else {
        throw MovieException("Invalid format");
    }
    system(command.c_str());
}

void MovieWatchlist::setFormat(const string &Format) {
    MovieWatchlist::format = Format;
}

bool MovieWatchlist::delete_movie_from_watchlist(const string &title, const string &genre, int year_of_release) {
    bool ok = false;
    for (auto it = this->movie_watchlist.begin(); it != this->movie_watchlist.end(); it++)
    {
        if ((*it)->get_title() == title && (*it)->get_genre() == genre && (*it)->get_year_of_release() == year_of_release)
        {
            this->movie_watchlist.erase(it);
            ok = true;
            break;
        }
    }

    if (ok) {
        if (format == "CSV" || format == "csv") {
            std::ofstream f("movie_watchlist.csv");
            if (!f) {
                throw MovieException("Unable to open file!\n");
            }
            for (auto & it : this->movie_watchlist) {
                f << *it;
            }
        }
        else if (format == "HTML" || format == "html") {
            std::ofstream f("movie_watchlist.html");
            if (!f) {
                throw MovieException("Unable to open file!\n");
            }
            f << "<!DOCTYPE html>" << std::endl;
            f << "<html>\n<head>\n\t<title>MovieWatchlist</title>\n<body>\n<table border=\"1\">\n<tr><th>Title</th><th>Genre</th><th>Year</th><th>Likes</th><th>Trailer</th></tr>";
            for (auto & it : this->movie_watchlist) {
                f << "<tr><td>" << it->get_title() << "</td><td>" << it->get_genre() << "</td><td>" << it->get_year_of_release() << "</td><td>" << it->get_number_of_likes() << "</td><td><a href=\"" << it->get_trailer_url() << "\">Watch Trailer</a></td></tr>";
            }
            f << "</table></body></html>";
        }
        else {
            throw MovieException("Invalid file format!\n");
        }
    }

    return ok;
}








