//
// Created by maksim on 21.02.24.
//

#ifndef UNTITLED_ARR_H
#define UNTITLED_ARR_H

#include <cstddef>
#include <vector>

class Arr {
private:
    std::vector<size_t> ans;
public:
    Arr();
    ~Arr();
    Arr(const Arr& other);
    Arr& operator=(const Arr& other);
    Arr(Arr&& other) noexcept;
    Arr& operator=(Arr&& other) noexcept;
    void add(size_t value);
    void print_data() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] std::vector<std::size_t> get_data() const;
};

#endif //UNTITLED_ARR_H
