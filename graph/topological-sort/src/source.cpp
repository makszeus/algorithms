#include <iostream>
#include <vector>
#include <stack>

void dfsTopo(int v, std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::stack<int>& st) {
    visited[v] = true;
    for (const auto& u : graph[v]) {
        if (!visited[u]) {
            dfsTopo(u, graph, visited, st);
        }
    }
    st.push(v);
}

void topologicalSort(std::vector<std::vector<int>>& graph) {
    size_t n = graph.size();
    std::vector<bool> visited(n, false);
    std::stack<int> st;

    for (size_t i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfsTopo(i, graph, visited, st);
        }
    }

    std::cout << "Topological order:\n";
    while (!st.empty()) {
        std::cout << st.top() + 1 << " ";
        st.pop();
    }
    std::cout << "\n";
}

int main() {
    int n = 6;
    std::vector<std::vector<int>> graph(n);

    graph[0] = {1, 2};   // 1 -> 2, 1 -> 3
    graph[1] = {3};      // 2 -> 4
    graph[2] = {3, 4};   // 3 -> 4, 3 -> 5
    graph[3] = {5};      // 4 -> 6
    graph[4] = {5};      // 5 -> 6

    topologicalSort(graph);
}
