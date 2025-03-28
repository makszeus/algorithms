#include <iostream>
#include <vector>

void dfs (const std::vector<std::vector<int>> &graph, std::vector<bool> &visited,
	std::vector<int> &result, int s) {
	visited[s] = true;
	result.push_back(s);

	for (int neighbor : graph[s]) {
		if (!visited[neighbor]) {
			dfs(graph, visited, result, neighbor);
		}
	}
}

int main() {
	std::vector<std::vector<int>> graph = {
        {1, 2},    	// 0 → 1, 2
        {0, 3, 4},  // 1 → 0, 3, 4
        {0, 5},     // 2 → 0, 5
        {1},        // 3 → 1
        {1},     	// 4 → 1
        {2}      	// 5 → 2
    };

    std::vector<int> traversal;
    std::vector<bool> isVisited(graph.size());

    dfs(graph, isVisited, traversal, 0);
    for (int node : traversal) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

	return 0;
}