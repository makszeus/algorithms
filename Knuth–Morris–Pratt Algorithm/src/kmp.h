//
// Created by maksim on 21.02.24.
//

#ifndef UNTITLED_KMP_H
#define UNTITLED_KMP_H

#include <string>
#include "arr.h"

size_t *pre_kmp(std::string pattern);
void kmp (const std::string &text, const std::string &pattern, Arr &arr);

#endif //UNTITLED_KMP_H
