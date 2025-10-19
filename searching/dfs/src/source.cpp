#include <iostream>
#include <queue>
#include <vector>

void dfs (int start, std::vector<std::vector<int>>& graph, std::vector <bool>& visited) {
    visited[start] = true;
    std::cout << start << "\n";

    for (const auto &u : graph[start]) {
        if(!visited[u]) {
            dfs(u, graph, visited);
        }
    }
}

int main() {

    int n = 5;
    std::vector<std::vector<int>> graph(n);
    std::vector <bool> dfs_visited(n, false);

    graph[0] = {1, 2, 3, 4};
    graph[1] = {0, 2, 3, 4};
    graph[2] = {0, 1, 3, 4};
    graph[3] = {0, 1, 2, 4};
    graph[4] = {0, 1, 2, 3};

    dfs(0, graph, dfs_visited);

    return 0;
}