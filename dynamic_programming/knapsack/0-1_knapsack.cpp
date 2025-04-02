#include <iostream>
#include <vector>

int knapsack(const int W, const std::vector<int>& weights, const std::vector<int>& values, const int N) {
    std::vector dp(N + 1, std::vector(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[N][W];
}

int knapsackOptimized(const int W, const std::vector<int>& weights, const std::vector<int>& values, const int N) {
    std::vector dp(W + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = std::max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

int main() {
    constexpr int W = 7;
    const std::vector weights = {1, 3, 4, 5};
    const std::vector values = {1, 4, 5, 7};
    const int N = weights.size();

    std::cout << knapsack(W, weights, values, N) << std::endl;
    std::cout << knapsackOptimized(W, weights, values, N) << std::endl;
    return 0;
}
