//
// Created by Alisia Kazimierek on 04/06/2024.
//

#ifndef ZORK_EXECEPTION_H
#define ZORK_EXECEPTION_H

#include <exception>
#include <string>

class Exeception : public std::exception{
public:
    explicit Exeception(const std::string& message) : message_(message) {}
        virtual const char* what() const noexcept override{
            return message_.c_str();
        }
private:
    std::string message_;
};


#endif //ZORK_EXECEPTION_H
