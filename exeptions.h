//
// Created by Leona on 4/21/2023.
//

#include <exception>
#include <string>
#include <utility>

#pragma  once

class MovieException : public std::exception {
private:
    std::string message;

public:
    explicit MovieException(std::string  msg) : message(std::move(msg)) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

