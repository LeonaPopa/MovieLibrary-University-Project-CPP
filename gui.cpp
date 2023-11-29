//
// Created by Leona on 5/16/2023.
//

#include <QMainWindow>
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <utility>
#include <QPalette>
#include <iostream>
#include "../header files/gui.h"

Gui::Gui(QWidget *parent, MovieService movieservice): QWidget(parent) , movieService(std::move(movieservice)){
    initGui();
    populateList();
    //populateWatchlist();
}

void Gui::populateList() {
    movieListWidget->clear();
    std::vector<Movie*> l=movieService.getAllMovies();
    std::vector<Movie *>::iterator i;
    for(i=l.begin(); i!=l.end(); i++)
        movieListWidget->addItem(QString::fromStdString((*i)->get_title()+ "---"+ (*i)->get_genre() + "---" + std::to_string((*i)->get_year_of_release())));
}

void Gui::initGui() {
    movieListWidget = new QListWidget();
    //menu - layout
    auto* mainLayout = new QVBoxLayout(this);
    modesWindow = new QWidget();
    adminWindow = new QWidget();
    userWindow = new QWidget();
    this->messageBox = new QMessageBox();
    this->messageBox->setText("Movie added!");
    not_added = new QMessageBox();
    not_added->setText("Movie not added!");
    removed = new QMessageBox();
    not_removed = new QMessageBox();
    removed->setText("Removed!");
    not_removed->setText("Not removed!");
    updated = new QMessageBox();
    updated->setText("Movie updated!");
    not_updated = new QMessageBox();
    not_updated->setText("Movie NOT updated");

    adminButton = new QPushButton("Admin mode");
    userCSVButton = new QPushButton("User CSV mode");
    userHTMLButton = new QPushButton("User HTML mode");
    image = new QLabel();
    QPixmap pixmap("../image.png");
    image->setPixmap(pixmap.scaled(475,430, Qt::KeepAspectRatio));

    modesWindow->setLayout(mainLayout);
    mainLayout->addWidget(image);
    mainLayout->addWidget(modesWindow);
    mainLayout->addWidget(adminButton);
    mainLayout->addWidget(userCSVButton);
    mainLayout->addWidget(userHTMLButton);


    modesWindow->setWindowTitle("Menu");
    modesWindow->setFixedSize(500, 500);

    //admin :
    main_layout = new QHBoxLayout();
    form_layout = new QFormLayout();
    vertical_layout = new QVBoxLayout();

    add_title = new QLineEdit();
    add_genre = new QLineEdit();
    add_year = new QLineEdit();
    add_likes = new QLineEdit();
    add_trailer = new QLineEdit();
    add_button = new QPushButton("ADD");

    remove_title = new QLineEdit();
    remove_year = new QLineEdit();
    remove_genre = new QLineEdit();
    remove_button = new QPushButton("REMOVE");

    update_title = new QLineEdit();
    update_genre = new QLineEdit();
    update_year = new QLineEdit();
    update_likes = new QLineEdit();
    update_button = new QPushButton("UPDATE");

    admin_back_button = new QPushButton("BACK");

    form_layout->addRow("Title", add_title);
    form_layout->addRow("Genre", add_genre);
    form_layout->addRow("Year of release", add_year);
    form_layout->addRow("Number of likes", add_likes);
    form_layout->addRow("Trailer url", add_trailer);
    form_layout->addWidget(add_button);

    form_layout->addRow("Title", remove_title);
    form_layout->addRow("Genre", remove_genre);
    form_layout->addRow("Year of release", remove_year);
    form_layout->addWidget(remove_button);

    form_layout->addRow("Title", update_title);
    form_layout->addRow("Genre", update_genre);
    form_layout->addRow("Year of release", update_year);
    form_layout->addRow("New number of likes", update_likes);
    form_layout->addWidget(update_button);

    vertical_layout->addWidget(movieListWidget);
    vertical_layout->addWidget(admin_back_button);

    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(form_layout);

    adminWindow->setLayout(main_layout);
    //=========================================================================
    watch_list = new QListWidget();

    user_form_layout = new QFormLayout();
    user_vertical_layout = new QVBoxLayout();
    user_main_layout = new QHBoxLayout();

    user_add_title = new QLineEdit();
    user_add_genre = new QLineEdit();
    user_add_year = new QLineEdit();

    user_remove_title = new QLineEdit();
    user_remove_genre = new QLineEdit();
    user_remove_year = new QLineEdit();

    user_selected_title = new QLineEdit();
    user_selected_genre = new QLineEdit();
    user_selected_year = new QLineEdit();

    user_filter_genre = new QLineEdit();
    watch_list_label = new QLabel("Watch-list:");
    selected = new QLabel("Selected movie:");
    user_vertical_layout->addWidget(watch_list_label);
    user_vertical_layout->addWidget(watch_list);

    user_add_button = new QPushButton("ADD");
    user_remove_button = new QPushButton("REMOVE");
    see_watch_list_button = new QPushButton("OPEN");
    user_back_button = new QPushButton("BACK");
    user_filter_button = new QPushButton("FILTER");
    user_next_button = new QPushButton("NEXT");

    user_vertical_layout->addWidget(user_back_button);

    user_form_layout->addRow("Title", user_add_title);
    user_form_layout->addRow("Genre", user_add_genre);
    user_form_layout->addRow("Year of release", user_add_year);
    user_form_layout->addWidget(user_add_button);

    user_form_layout->addRow("Title", user_remove_title);
    user_form_layout->addRow("Genre", user_remove_genre);
    user_form_layout->addRow("Year of release", user_remove_year);
    user_form_layout->addWidget(user_remove_button);

    user_form_layout->addRow("Filter after genre:", user_filter_genre);
    user_form_layout->addWidget(user_filter_button);

    user_form_layout->addWidget(selected);
    user_form_layout->addRow("Title", user_selected_title);
    user_form_layout->addRow("Genre", user_selected_genre);
    user_form_layout->addRow("Year of release", user_selected_year);
    user_form_layout->addRow(see_watch_list_button, user_next_button);

    user_main_layout->addWidget(movieListWidget);
    user_main_layout->addLayout(user_vertical_layout);
    user_main_layout->addLayout(user_form_layout);

    userWindow->setLayout(user_main_layout);

    QObject::connect(this->adminButton, &QPushButton::clicked, this, &Gui::showAdminwindow);
    QObject::connect(this->admin_back_button, &QPushButton::clicked, this, &Gui::startUpMenu);
    QObject::connect(this->user_back_button, &QPushButton::clicked, this, &Gui::startUpMenu);
    QObject::connect(this->userCSVButton, &QPushButton::clicked, this, &Gui::showCSVWindow);
    QObject::connect(this->userHTMLButton, &QPushButton::clicked, this, &Gui::show_html_window);

    QObject::connect(this->add_button, &QPushButton::clicked, this, &Gui::add_movie_admin);
    QObject::connect(this->remove_button, &QPushButton::clicked, this, &Gui::remove_movie_admin);
    QObject::connect(this->update_button, &QPushButton::clicked, this, &Gui::update_movie_admin);

    QObject::connect(this->user_add_button, &QPushButton::clicked, this, &Gui::add_movie_user);
    QObject::connect(this->user_remove_button, &QPushButton::clicked, this, &Gui::remove_movie_user);
    QObject::connect(this->user_filter_button, &QPushButton::clicked, this, &Gui::filter_movie_user);

    QObject::connect(this->movieListWidget, &QListWidget::clicked, this, &Gui::movie_list_item_clicked);
    QObject::connect(this->user_next_button, &QPushButton::clicked, this, &Gui::user_next);
    QObject::connect(this->see_watch_list_button, &QPushButton::clicked, this, &Gui::user_open);
    startUpMenu();
}

void Gui::startUpMenu() {
    this->adminWindow->setVisible(false);
    this->userWindow->setVisible(false);
    this->modesWindow->setVisible(true);
}

void Gui::showCSVWindow(){
    this->userWindow->setVisible(true);
    this->modesWindow->setVisible(false);
    this->adminWindow->setVisible(false);
    movie_watchlist.setFormat("csv");
}

void Gui::showAdminwindow() {
    this->userWindow->setVisible(false);
    this->modesWindow->setVisible(false);
    this->adminWindow->setVisible(true);
}

void Gui::populateWatchlist() {
    watch_list->clear();
    std::vector<Movie*> l=movie_watchlist.getMovies();
    std:: cout << l.size();
    std::vector<Movie *>::iterator i;
    for(i=l.begin(); i!=l.end(); i++)
        watch_list->addItem(QString::fromStdString((*i)->get_title()+ "---"+ (*i)->get_genre() + "---" + std::to_string((*i)->get_year_of_release())));
}

void Gui::add_movie_admin() {
    try{
        string title;
        title = add_title->text().toStdString();
        string genre;
        genre = add_genre->text().toStdString();
        int year = this->add_year->text().toInt();
        int likes = this->add_likes->text().toInt();
        string trailer;
        trailer = this->add_trailer->text().toStdString();
        this->movieService.add(title, genre, year, likes, trailer);
        this->messageBox->exec();
    }catch (MovieException &ex){
        not_added->exec();
    }
    this->populateList();
    clear_admin();
}

void Gui::clear_admin() {

    add_title->clear();
    add_genre->clear();
    add_year->clear();
    add_likes->clear();
    add_trailer->clear();
    remove_title->clear();
    remove_year->clear();
    remove_genre->clear();

    update_title->clear();
    update_genre->clear();
    update_year->clear();
    update_likes->clear();
}

void Gui::remove_movie_admin() {
    try{
        string title;
        title = remove_title->text().toStdString();
        string genre;
        genre = remove_genre->text().toStdString();
        int year = this->remove_year->text().toInt();
        this->movieService.remove_service(title, genre, year);
        this->removed->exec();
    }catch (MovieException &ex){
        not_removed->exec();
    }
    this->populateList();
    clear_admin();
}

void Gui::update_movie_admin() {
    try{
        string title;
        title = update_title->text().toStdString();
        string genre;
        genre = update_genre->text().toStdString();
        int year = this->update_year->text().toInt();
        int likes = this->update_likes->text().toInt();
        Movie * new_movie = movieService.get_movie(title, genre, year);
        this->movieService.update_number_of_likes(new_movie, likes);
        this->updated->exec();
    }catch (MovieException &ex){
        not_updated->exec();
    }
    this->populateList();
    clear_admin();
}

void Gui::add_movie_user() {
    try{
        string title;
        title = user_add_title->text().toStdString();
        string genre;
        genre = user_add_genre->text().toStdString();
        int year = this->user_add_year->text().toInt();
        Movie * new_movie = movieService.get_movie(title, genre, year);
        this->movie_watchlist.add_movie_to_watchlist(new_movie);
        this->messageBox->exec();
    }catch (MovieException &ex){
        not_added->exec();
    }
    this->populateWatchlist();
    this->populateList();
    clear_user();
}

void Gui::clear_user() {
    user_add_title->clear();
    user_add_genre->clear();
    user_add_year->clear();

    user_remove_title->clear();
    user_remove_genre->clear();
    user_remove_year->clear();

    user_filter_genre->clear();
    user_selected_title->clear();
    user_selected_genre->clear();
    user_selected_year->clear();
}

void Gui::remove_movie_user() {
    try{
        string title;
        title = user_remove_title->text().toStdString();
        string genre;
        genre = user_remove_genre->text().toStdString();
        int year = this->user_remove_year->text().toInt();
        this->movie_watchlist.delete_movie_from_watchlist(title, genre, year);
        this->removed->exec();
    }catch (MovieException &ex){
        not_removed->exec();
    }
    this->populateWatchlist();
    this->populateList();
    clear_user();
}

void Gui::filter_movie_user() {
    try {
        string genre;
        genre = user_filter_genre->text().toStdString();
        movieListWidget->clear();
        std::vector<Movie *> l = movieService.getAllMovies();
        std::vector<Movie *>::iterator i;
        for (i = l.begin(); i != l.end(); i++)
            if ((*i)->get_genre() == genre)
                movieListWidget->addItem(QString::fromStdString((*i)->get_title() + "---" + (*i)->get_genre() + "---" +
                                                                std::to_string((*i)->get_year_of_release())));
    }catch (MovieException &ex){
        //
    }
    clear_user();
}

void Gui::movie_list_item_clicked() {
    int selected_index ;
    QModelIndexList  indexList = movieListWidget->selectionModel()->selectedIndexes();
    selected_index = indexList[0].row();
    Movie *movie = movieService.get_movie(selected_index);
    user_selected_title->setText(QString::fromStdString(movie->get_title()));
    user_selected_genre->setText(QString::fromStdString(movie->get_genre()));
    user_selected_year->setText(QString::fromStdString(std::to_string(movie->get_year_of_release())));
}

void Gui::user_next() {
    int selected_index ;
    QModelIndexList  indexList = movieListWidget->selectionModel()->selectedIndexes();
    selected_index = indexList[0].row();
    Movie *movie = movieService.get_movie(selected_index+1);
    user_selected_title->setText(QString::fromStdString(movie->get_title()));
    user_selected_genre->setText(QString::fromStdString(movie->get_genre()));
    user_selected_year->setText(QString::fromStdString(std::to_string(movie->get_year_of_release())));
}

void Gui::user_open() {
    movie_watchlist.open_file();
    user_selected_title->clear();
    user_selected_genre->clear();
    user_selected_year->clear();
}

void Gui::show_html_window() {
    this->userWindow->setVisible(true);
    this->modesWindow->setVisible(false);
    this->adminWindow->setVisible(false);
    movie_watchlist.setFormat("html");
}





