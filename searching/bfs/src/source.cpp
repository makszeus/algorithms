#include <iostream>
#include <queue>
#include <vector>

void bfs (int start, std::vector<std::vector<int>>& graph) {
    size_t n = graph.size();
    std::queue <int> q;
    std::vector <bool> visited(n, false);

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int v = q.front(); q.pop();
        std::cout << v + 1 << "\n";

        for (const auto &u : graph[v]) {
            std::cout << "neigh: " << u + 1 << "\n";
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            } 
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

    std::cout << "BFS starting from 0:\n";
    bfs(0, graph);

    return 0;
}