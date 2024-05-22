# Movie Library - University Project

## Overview

This project is a C++ application developed as a university assignment. It features a movie library where users can add, remove, update movies, and manage a watch list. The application includes a graphical user interface (GUI) developed using the Qt framework. Additionally, the project implements undo and redo functionality for various operations using inheritance and polymorphism.

## Features

- **Add, Remove, Update Movies**: Manage a collection of movies with basic CRUD operations.
- **Undo/Redo Functionality**: Support for undo and redo operations for add, remove, and update actions.
- **Watch List Management**: Manage a watch list of movies, including viewing and removing movies from the list.
- **Qt GUI**: A graphical user interface built with Qt, featuring:
  - **QTableView**: Display the watch list using a table view.
  - **Undo/Redo Buttons**: Buttons and key combinations (`Ctrl+Z`, `Ctrl+Y`) for undo and redo operations.

## Requirements

1. **Undo/Redo Functionality**:
   - Implemented for add, remove, and update operations.
   - Available through GUI buttons and key combinations (`Ctrl+Z` for undo, `Ctrl+Y` for redo).

2. **Watch List Display**:
   - Display the contents of the watch list using a `QTableView`.
   - Custom model inherited from `QAbstractTableModel` to manage the data displayed in the table.

## File Structure

- **domain.cpp/h**: Contains the domain classes and their implementations.
- **exceptions.h**: Defines custom exceptions used in the application.
- **gui.cpp/h**: Implements the graphical user interface using Qt.
- **repository.cpp/h**: Manages the storage and retrieval of movie data.
- **service.cpp/h**: Implements the business logic of the application.
- **ui.cpp/h**: Handles the user interface logic.
- **validator.cpp/h**: Validates movie data.
- **watch_list.cpp/h**: Manages the watch list functionality.
- **CMakeLists.txt**: Build configuration file for CMake.
- **README.md**: Project documentation.




# Assignment 10

## Requirements
1. Add multiple *undo* and *redo* functionality for the `add`, `remove`, and `update` operations. Implement this functionality using inheritance and polymorphism. You will have **Undo** and **Redo** buttons on the GUI, as well as a key combination to undo and redo the operations (e.g. `Ctrl+Z`, `Ctrl+Y`).

2. Show the contents of the `adoption list` / `movie watch list` / `shopping basket` / `tutorial watch list` using a table view. You must use the [Qt View/Model](https://doc.qt.io/qt-6/modelview.html) components (`QTableView`). Create your own model – a class which inherits from [`QAbstractTableModel`](https://doc.qt.io/qt-6/qabstracttablemodel.html). This window will be opened from your GUI's main window.

