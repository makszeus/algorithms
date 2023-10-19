#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS traversal
void bfs(int start, vector<bool>& visited, vector<vector<int>>& graph) {
    queue<int> q;
    q.push(start);                           // Enqueue the starting node
    visited[start] = true;                   // Mark the starting node as visited

    while (!q.empty()) {
        int node = q.front();
        q.pop();                             // Dequeue the current node

        cout << node << " ";                 // Process the current node

        for (int nextNode : graph[node]) {
            if (!visited[nextNode]) {        // If the next node is not visited
                q.push(nextNode);            // Enqueue the next node
                visited[nextNode] = true;    // Mark the next node as visited
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    vector<vector<int>> graph(numNodes);     // Create an adjacency list to represent the graph

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(numNodes, false);   // Create a visited array to track visited nodes

    cout << "BFS traversal: ";
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {                     // If the node is not visited, perform BFS on it
            bfs(i, visited, graph);
        }
    }

    cout << endl;

    return 0;
}
