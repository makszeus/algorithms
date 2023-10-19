#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal
void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[node] = true;                      // Mark the current node as visited
    cout << node << " ";                        // Process the current node

    for (int i = 0; i < graph[node].size(); ++i) {
        int nextNode = graph[node][i];          // Get the next adjacent node

        if (!visited[nextNode]) {               // If the next node is not visited
            dfs(nextNode, visited, graph);      // Recursively call dfs on the next node
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    vector<vector<int>> graph(numNodes);        // Create an adjacency list to represent the graph

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(numNodes, false);      // Create a visited array to track visited nodes

    cout << "DFS traversal: ";
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {                       // If the node is not visited, perform DFS on it
            dfs(i, visited, graph);
        }
    }

    cout << endl;

    return 0;
}
