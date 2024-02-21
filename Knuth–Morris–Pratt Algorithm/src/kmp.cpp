//
// Created by maksim on 21.02.24.
//

#include "exc.h"
#include "kmp.h"
size_t *pre_kmp(std::string pattern) {

    size_t size_ = pattern.size();
    auto *pie = new size_t [size_];

    pie[0] = 0;
    size_t k = 0;

    for (size_t i = 1; i < size_; ++i) {

        while (k > 0 && pattern[k] != pattern[i]) k = pie[k - 1];
        if (pattern[k] == pattern[i]) k = k + 1;

        pie[i] = k;

    }

    return pie;

}

void kmp (const std::string &text, const std::string &pattern, Arr &arr) {

    size_t* pre_ = pre_kmp(pattern);
    size_t matched_pos = 0;
    for (size_t i = 0; i < text.length(); ++i) {

        while (matched_pos > 0 && pattern[matched_pos] != text[i]) matched_pos = pre_[matched_pos - 1];

        if (pattern[matched_pos] == text[i]) matched_pos = matched_pos + 1;

        if (matched_pos == (pattern.length())) {
            arr.add((i - (pattern.length() - 1)));
            matched_pos = pre_[matched_pos - 1];
        }

    }

    if (arr.isEmpty()) throw exc("The substring didn't found.");

}
