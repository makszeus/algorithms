//
// Created by maksim on 21.02.24.
//

#include "exc.h"

// Конструктор с параметром
exc::exc(std::string ss) : s(std::move(ss)) {}

// Деструктор
exc::~exc() noexcept = default;

// Метод what
const char* exc::what() const noexcept {
    return s.c_str();
}
