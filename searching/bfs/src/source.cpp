#include <iostream>
#include <queue>
#include <vector>

void bfs (const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, 
	std::vector <int> &result, int s) {
	std::queue <int> q;
	
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		s = q.front();
		q.pop();
		result.push_back(s);

		for (int neighbor : graph[s]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

int main() {
	std::vector<std::vector<int>> graph = {
        {1, 2},    	// 0 → 1, 2
        {0, 3, 4},  // 1 → 0, 3, 4
        {0, 5},     // 2 → 0, 5
        {1},        // 3 → 1
        {1, 5},     // 4 → 1, 5
        {2, 4}      // 5 → 2, 4
    };

    std::vector<int> traversal;
    std::vector<bool> isVisited(graph.size());
    bfs(graph, isVisited, traversal, 2);
    for (int node : traversal) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}