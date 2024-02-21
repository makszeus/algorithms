//
// Created by maksim on 21.02.24.
//

#ifndef UNTITLED_EXC_H
#define UNTITLED_EXC_H

#include <string>
#include <utility>
#include <exception>

struct exc : public std::exception {
    std::string s;
    explicit exc(std::string ss);
    ~exc() noexcept override;
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //UNTITLED_EXC_H
