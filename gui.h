//
// Created by Leona on 5/16/2023.
//

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include "service.h"
#include "watch_list.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QWidget>
#include <qlayout.h>
#include <qline.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qstackedlayout.h>
#include <QFormLayout>


#ifndef ASSIGNMENT8_GUI_H
#define ASSIGNMENT8_GUI_H

#endif //ASSIGNMENT8_GUI_H

class Gui: public QWidget{
    Q_OBJECT
public:
    explicit Gui(QWidget *parent = nullptr, MovieService movieService = MovieService());
private:
    MovieService movieService;
    MovieWatchlist movie_watchlist;
    //start-up menu:
    QWidget *modesWindow;
    QWidget *adminWindow;
    QWidget *userWindow;

    QPushButton *adminButton;
    QPushButton *userCSVButton;
    QPushButton *userHTMLButton;

    QLabel *image;

    //admin:
    QFormLayout *form_layout;
    QVBoxLayout *vertical_layout;
    QHBoxLayout *main_layout;
    //line edits:
    QLineEdit *add_title;
    QLineEdit *add_genre;
    QLineEdit *add_year;
    QLineEdit *add_likes;
    QLineEdit *add_trailer;
    QPushButton *add_button;
    //
    QLineEdit *remove_title;
    QLineEdit *remove_genre;
    QLineEdit *remove_year;
    QPushButton *remove_button;
    //
    QLineEdit *update_title;
    QLineEdit *update_genre;
    QLineEdit *update_year;
    QLineEdit *update_likes;
    QPushButton *update_button;

    QPushButton * admin_back_button;
    //admin widget list:
    QListWidget* movieListWidget;


    //user
    QListWidget *watch_list;
    QLabel *watch_list_label;
    QLabel *selected;
    QFormLayout *user_form_layout;
    QVBoxLayout *user_vertical_layout;
    QHBoxLayout *user_horizontal_layout;
    QHBoxLayout *user_main_layout;

    QLineEdit *user_add_title;
    QLineEdit *user_add_genre;
    QLineEdit *user_add_year;

    QLineEdit *user_remove_title;
    QLineEdit *user_remove_genre;
    QLineEdit *user_remove_year;

    QLineEdit *user_selected_title;
    QLineEdit *user_selected_genre;
    QLineEdit *user_selected_year;

    QLineEdit *user_filter_genre;

    QPushButton *user_add_button;
    QPushButton *user_remove_button;
    QPushButton *see_watch_list_button;
    QPushButton *user_back_button;
    QPushButton *user_filter_button;
    QPushButton *user_next_button;

    QMessageBox *messageBox;
    QMessageBox *not_added;

    QMessageBox *removed;
    QMessageBox *not_removed;

    QMessageBox *updated;
    QMessageBox *not_updated;
private:
    void populateList();
    void initGui();
    void startUpMenu();
    void showAdminwindow();
    void showCSVWindow();
    void populateWatchlist();
    void add_movie_admin();
    void clear_admin();
    void remove_movie_admin();
    void update_movie_admin();
    void add_movie_user();
    void clear_user();
    void remove_movie_user();
    void filter_movie_user();
    void movie_list_item_clicked();
    void user_next();
    void user_open();
    void show_html_window();
};