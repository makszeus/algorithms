//
// Created by maksim on 21.02.24.
//

#include <gtest/gtest.h>
#include "arr.h"
#include "exc.h"
#include "kmp.h"

TEST(KmpTest, Test1) {
    std::string text = "abcabcabc";
    std::string pattern = "abc";
    Arr arr;
    kmp(text, pattern, arr);
    std::vector<size_t> expected = {0, 3, 6};
    ASSERT_EQ(arr.get_data(), expected);
}

TEST(KmpTest, Test2) {
    std::string text = "abcabcabc";
    std::string pattern = "d";
    Arr arr;
    try {
        kmp(text, pattern, arr);
        FAIL() << "Expected exc";
    }
    catch(exc const & err) {
        EXPECT_EQ(err.what(),std::string("The substring didn't found."));
    }
    catch(...) {
        FAIL() << "Expected exc";
    }
}

TEST(KmpTest, Test3) {
    std::string text = "aaaaaaaaaaaaaaaaaalabamaaaalabamaalabamaaa";
    std::string pattern = "alabama";
    Arr arr;
    kmp(text, pattern, arr);
    std::vector<size_t> expected = {17, 26, 33};
    ASSERT_EQ(arr.get_data(), expected);
}
