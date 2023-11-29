
#include "../../Assignment8/header files/ui.h"
#include<iostream>
#include<ostream>
#include <cstring>
#include <shlwapi.h>
#include <thread>
#include <algorithm>

using namespace std;

void MovieUi::print_menu_options(int menu){
    if (menu == 1) {
        cout << "Option 1:administrator mode\n";
        cout << "Option 2:user mode\n";
        cout << "Option 3:exit\n";
        cout << ">>>";
    }
    else
    if(menu == 2)
    {
        cout << "Option 1: Add a new movie;\n";
        cout << "Option 2: Remove a movie;\n";
        cout << "Option 3: update number of likes;\n";
        cout << "Option 4: update trailer url;\n";
        cout << "Option 5: see all movies;\n";
        cout << "Option 6: exit;\n";
        cout << ">>>";
    }
    else
    if(menu == 3)
    {
        cout << "Option 1: See the movies with a given genre;\n";
        cout << "Option 2: Add movie to watch list;\n";
        cout << "Option 3: Delete movie from watch list;\n";
        cout << "Option 4: See watch list;\n";
        cout << "Option 5: exit;\n";
        cout << ">>>";
    }
}

void MovieUi::mode()
{

    char option[100];
    int o;
    while (true)
    {
        this->print_menu_options(1);
        cin.getline(option, 100);
        if (!MovieValidator::is_number(option))
        {
            cout<< "wrong command";
            continue;
        }
        else
            o = atoi(option);
        if (o == 3)
            break;
        switch(o){
            case 1:
            {this->run_menu_admin();
                break;}
            case 2:
            {this->run_menu_user();
                break;}
            default: break;
        }
    }
}

void MovieUi::run_menu_admin()
{
    char option[100];int o;
    while (true)
    {
        this->print_menu_options(2);
        cin.getline(option, 100);
        if (!MovieValidator::is_number(option))
        {
            cout << "wrong command\n";
            continue;
        }
        else
            o = atoi(option);
        if (o == 1)
            this->add_movie();
        else if (o == 2)
            this->remove_movie();
        else if (o == 3)
            this->update_number_of_likes();
        else if (o == 4)
            this->update_trailer_url();
        else if (o == 5)
            this->print_all_movies();
        else if (o == 6)
            break;
        else
            std::cout << "That is not a valid option\n";
    }
}

void MovieUi::run_menu_user()
{
    cout << endl;
    cout << "CSV or HTML"<<endl;
    char option[100];int o;
    cin.getline(option, 100);

    if (strcmp(option, "csv") == 0){
        this->watch_list.setFormat("csv");
    }
    else
        if(strcmp(option, "html") == 0){
            this->watch_list.setFormat("html");
            }
        else
            return;

    while (true)
    {
        this->print_menu_options(3);
        cin.getline(option, 100);
        if (!MovieValidator::is_number(option))
        {
            cout << "wrong command\n";
            continue;
        }
        else
            o = atoi(option);
        if (o == 1)
            this->see_all_movies_with_a_given_genre();
        else if (o == 2)
            this->add_movie_to_watch_list();
        else if (o == 3)
            this->delete_from_watch_list();
        else if (o == 4)
            this->see_watch_list();
        else if (o == 5)
            break;
        else
            std::cout << "That is not a valid option\n";
    }
}

void MovieUi::add_movie_to_watch_list()
{
    char title[100], genre[100], year[100]; int year_of_release;
    cout << "\n Enter the title of the movie you want to add to your watch list>>>";
    cin.getline(title, 100);
    if (!MovieValidator::is_valid_title(title))
    {
        cout << "Invalid title!\n";
        return;
    }
    cout << "\n Enter the genre>>>";
    cin.getline(genre, 100);
    if (!MovieValidator::is_valid_genre(genre))
    {
        cout << "Invalid genre!\n";
        return;
    }
    while (true)
    {
        cout << "\nEnter the year of release>>>";
        cin.getline(year, 100);
        if (!MovieValidator::is_number(year))
        {
            cout << "Wrong year! Please enter again!\n";
            continue;
        }
        else{
            year_of_release = atoi(year);
            if (!MovieValidator::is_valid_year(year_of_release)) {
                cout << "Invalid year! Please enter again!\n";
                continue;
            } else
            {
                break;
            }
        }
    }
    try {
        this->watch_list.add_movie_to_watchlist(this->ui.get_movie(title, genre, year_of_release));
        cout << "\nThe movie has been added!\n";
    }catch (const MovieException& ex){
        std::cout << "Error: " << ex.what() << std::endl;
        cout<< "\n The movie could not be added\n";
    }

}

void MovieUi::add_movie()
{
    char title[100], genre[100], year[100], likes[100], trailer_url[1000]; int year_of_release, number_of_likes;
    cout << "\n Enter the title>>>";
    cin.getline(title, 100);
    cout << "\n Enter the genre>>>";
    cin.getline(genre, 100);
    while (true)
    {
        cout << "\nEnter the year of release>>>";
        cin.getline(year, 100);
        if (!MovieValidator::is_number(year))
        {
            cout << "Wrong year! Please enter again!\n";
            continue;
        }
        else{
            year_of_release = atoi(year);
            break;
        }
    }
    while (true)
    {
        cout << "\nEnter the number_of_likes>>>";
        cin.getline(likes, 100);
        if (!MovieValidator::is_number(likes))
        {
            cout << "Wrong number of likes! Please enter again\n";
            continue;
        }
        else{
            number_of_likes = atoi(likes);
            if(!MovieValidator::is_valid_likes(number_of_likes))
                continue;
            else
                break;
        }
    }
    cout << "\nEnter the url of the trailer>>> ";
    cin.getline(trailer_url, 1000);
    if(!MovieValidator::is_valid_trailer(trailer_url)) {
        cout<<"trailer not valid!\n";
        return;
    }
    else
    try {
        this->ui.add(title, genre, year_of_release, number_of_likes, trailer_url);
        cout << "\nThe movie has been added!\n";
    }catch(const MovieException& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
}

void MovieUi::remove_movie()
{
    char title[100], genre[100], year[100]; int year_of_release;
    cout << "\n Enter the title>>>";
    cin.getline(title, 100);
    cout << "\n Enter the genre>>>";
    cin.getline(genre, 100);
    while (true)
    {
        cout << "\nEnter the year of release>>>";
        cin.getline(year, 100);
        if (!MovieValidator::is_number(year))
        {
            cout << "Wrong year! Please enter again!\n";
            continue;
        }
        else{
            year_of_release = atoi(year);
            break;
        }
    }
    bool ok = this->ui.remove_service(title, genre, year_of_release);
    if(ok)
        cout << "The movie has been removed!\n";
    else
        cout << "The movie has NOT been removed!\n";
}

void MovieUi::update_number_of_likes()
{
    char title[100], genre[100], year[100]; int year_of_release;
    cout << "\n Enter the title>>>";
    cin.getline(title, 100);
    cout << "\n Enter the genre>>>";
    cin.getline(genre, 100);
    while (true)
    {
        cout << "\nEnter the year of release>>>";
        cin.getline(year, 100);
        if (!MovieValidator::is_number(year))
        {
            cout << "Wrong year! Please enter again!\n";
            continue;
        }
        else{
            year_of_release = atoi(year);
            break;
        }
    }
    char likes[100];int new_number;
    while (true)
    {
        cout << "\nEnter the new number of likes>>>";
        cin.getline(likes, 100);
        if (!MovieValidator::is_number(likes))
        {
            cout << "Wrong number of likes! Please enter again\n";
            continue;
        }
        else{
            new_number = atoi(likes);
            break;
        }
    }
    Movie *movie;
    try {
        movie = this->ui.get_movie(title, genre, year_of_release);
        try {
            ui.update_number_of_likes(movie, new_number);
            cout << "The number of likes has been updated!\n";
        }catch(const MovieException&ex){
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }catch(const MovieException&ex){
        cout << "error:"<< ex.what()<<endl;
    }
}

void MovieUi::update_trailer_url()
{

    char title[100], genre[100], year[100], trailer_url[1000]; int year_of_release;
    cout << "\n Enter the title>>>";
    cin.getline(title, 100);
    cout << "\n Enter the genre>>>";
    cin.getline(genre, 100);
    while (true)
    {
        cout << "\nEnter the year of release>>>";
        cin.getline(year, 100);
        if (!MovieValidator::is_number(year))
        {
            cout << "Wrong year! Please enter again!\n";
            continue;
        }
        else{
            year_of_release = atoi(year);
            break;
        }
    }
    cout << "\n Enter the new_trailer_url>>>";
    cin.getline(trailer_url, 1000);
    try {
        Movie *movie = this->ui.get_movie(title, genre, year_of_release);
        try {
            ui.update_trailer_url(movie, trailer_url);
            cout << "The trailer has been updated!\n";
        }catch (const MovieException& ex){
            std::cout<<"couldn't update!\n";
        }
    }catch(const MovieException&ex)
    {
        cout << "The trailer has NOT been updated!\n";
    }

}

void MovieUi::print_all_movies()
{
    for (int i = 0; i < this->ui.get_nr_movies(); i++)
        cout<<this->ui.get_movie(i)->get_title()<<" "<<this->ui.get_movie(i)->get_genre()<<" "<< this->ui.get_movie(i)->get_year_of_release()<<" "<<this->ui.get_movie(i)->get_number_of_likes()<<" "<<this->ui.get_movie(i)->get_trailer_url()<< '\n';
}

void MovieUi::see_all_movies_with_a_given_genre() {
    char option[100];
    char genre[100];
    int nr;
    cout << "\n Enter the genre>>>";
    cin.getline(genre, 100);
    cout << "\n";
    cout << "\n";
    nr = std::count_if(this->ui.movie_service.movie_repository.begin(), this->ui.movie_service.movie_repository.end(),
                       [genre](Movie *movie) {
                           return movie->get_genre() <= genre || strcmp(genre, "") == 0;
                       });
    if (nr == 0) {
        cout << "There are no movies with that genre!";
        return;
    }

    for (int i = 0; i < this->ui.get_nr_movies(); i++) {
        if (this->ui.get_movie(i)->get_genre() <= genre || strcmp(genre, "") == 0) {
            cout << "Title " << this->ui.get_movie(i)->get_title() << ";\n";
            cout << "Genre " << this->ui.get_movie(i)->get_genre() << ";\n";
            cout << "Year of release " << this->ui.get_movie(i)->get_year_of_release() << ";\n";
            cout << "Number of likes " << this->ui.get_movie(i)->get_number_of_likes() << ";\n";
            std::this_thread::sleep_for(4s);
            std::string trailerUrl = this->ui.get_movie(i)->get_trailer_url();
            auto lpstrTrailerUrl = const_cast<char*>(trailerUrl.c_str());
            STARTUPINFO si;
            PROCESS_INFORMATION pi;
            ZeroMemory(&si, sizeof(STARTUPINFO));
            si.cb = sizeof(STARTUPINFO);
            ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
            CreateProcess(nullptr, reinterpret_cast<LPWSTR>(lpstrTrailerUrl), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
            nr++;
            cout << "Did you enjoy the trailer?(Y/N)\n";
            cin.getline(option, 100);
            if (option[0] == 'Y' || option[0] == 'y') {
                cout << "Do you want to add the movie to your watch list?";
                cin.getline(option, 100);
                if (option[0] == 'Y' || option[0] == 'y') {
                    this->watch_list.add_movie_to_watchlist(this->ui.get_movie(i));
                    cout << "Movie added to watch list!";
                }

            }
            cout << "\nDo you want to continue? (Y/N)\n";
            cin.getline(option, 100);
            if (option[0] != 'y' && option[0] != 'Y')
                break;

        }
    }
    cout << "\nDo you want to continue? (Y/N)\n";
    cin.getline(option, 100);
    if (option[0] == 'Y' || option[0] == 'y')
        see_all_movies_with_a_given_genre();
}

void MovieUi::see_watch_list() {
    watch_list.open_file();
}

void MovieUi::delete_from_watch_list() {

    char title[100], genre[100], year[100], option[100]; int year_of_release;
    cout << "\n Enter the title>>>";
    cin.getline(title, 100);
    cout << "\n Enter the genre>>>";
    cin.getline(genre, 100);
    while (true)
    {
        cout << "\nEnter the year of release>>>";
        cin.getline(year, 100);
        if (!MovieValidator::is_number(year))
        {
            cout << "Wrong year! Please enter again!\n";
            continue;
        }
        else{
            year_of_release = atoi(year);
            break;
        }
    }
    bool ok;
    try {
        ok = this->watch_list.delete_movie_from_watchlist(title, genre, year_of_release);
    }catch(const MovieException&ex){
        std::cout<<"error:"<<ex.what()<<endl;
    }
    if(ok)
    {   cout << "The movie has been removed!\n";
        cout << "\n Did you like the movie(y/n)>>>";
        cin.getline(option, 100);
        if(option[0] == 'Y' || option[0]== 'y')
            this->ui.get_movie(title, genre,year_of_release)->set_number_of_likes(this->ui.get_movie(title,genre,year_of_release)->get_number_of_likes()+1);
    }

    else
        cout << "The movie has NOT been removed!\n";
}

MovieUi::MovieUi() {
    this->ui.movie_service.load_from_file();
}
