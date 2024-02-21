//
// Created by maksim on 21.02.24.
//

#include "arr.h"
#include <iostream>

Arr::Arr() = default;

Arr::~Arr() = default;

Arr::Arr(const Arr& other) = default;

Arr& Arr::operator=(const Arr& other) {
    if (this != &other) {
        ans = other.ans;
    }
    return *this;
}

Arr::Arr(Arr&& other) noexcept : ans(std::move(other.ans)) {}

Arr& Arr::operator=(Arr&& other) noexcept {
    if (this != &other) {
        ans = std::move(other.ans);
    }
    return *this;
}

void Arr::add(size_t value) {
    ans.push_back(value);
}

void Arr::print_data() const {
    for (const auto& element : ans) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

bool Arr::isEmpty() const {
    return ans.empty();
}

std::vector<std::size_t> Arr::get_data() const {
    return ans;
}
