#include <iostream>
#include <vector>

size_t lengthOfLIS(std::vector <int>& nums) {
    std::vector <int> dp;

    for (const auto &num : nums) {
        auto it = std::lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num);
        } else {
            *it = num;
        }
    }
    return dp.size();
}

int main() {

    std::vector<int> v = {10,9,2,5,3,7,101,18};
    size_t x = lengthOfLIS(v);
    std::cout << x << "\n";
    return 0;
}