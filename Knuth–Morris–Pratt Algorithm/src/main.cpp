#include "arr.h"
#include "kmp.h"

#include <gtest/gtest.h>
#include <iostream>
#include <string>

int main() {

    std::string text, pattern;
    Arr arr;

    std::cin >> text >> pattern;

    kmp(text, pattern, arr);

    arr.print_data();

    return 0;

}
