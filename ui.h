//
// Created by Leona on 4/13/2023.
//

#include "../../Assignment8/header files/service.h"
#include "validator.h"
#include "watch_list.h"
#pragma  once
class MovieUi {
private:
    MovieService ui;
    MovieWatchlist watch_list;
public:
    void mode();
    void run_menu_admin();
    void add_movie();
    void remove_movie();
    void update_number_of_likes();
    void update_trailer_url();
    void print_all_movies();
    static void print_menu_options(int);
    void run_menu_user();
    void add_movie_to_watch_list();
    void see_all_movies_with_a_given_genre();
    void see_watch_list();
    void delete_from_watch_list();
    MovieUi();
};