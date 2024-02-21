#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

class Graph {
private:
    int V; // No. of vertices
    int *prev; // Previous vertex
    std::vector<int> *adj; // Pointer to an array containing adjacency lists
    std::vector<int> *wgt; // Pointer to an array containing weights

public:
    explicit Graph(int V); // Constructor
    Graph() : V(0), prev(nullptr), adj(nullptr), wgt(nullptr) {} // default constructor
    void addEdge(int v, int w, int wt); // Add an edge to the graph
    void BFS(int s, int t); // Breadth First Search
    void displayPath(int f); // Display the path
    void init(int V_); // Initialization of the graph
};

Graph::Graph(int V) {
    
    this->V = V;
    adj = new std::vector<int>[V];
    wgt = new std::vector<int>[V];
    prev = new int[V];
    
}

void Graph::addEdge(int v, int w, int wt) {

    adj[v].push_back(w);
    wgt[v].push_back(wt);
    adj[w].push_back(v);
    wgt[w].push_back(wt);

}

void Graph::BFS(int s, int t) {

    bool *visited = new bool[V];

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    std::list<int> queue;
    int current;
    visited[s] = true;
    prev[s] = -1;
    queue.push_back(s);
    std::vector<int>::iterator i;

    while(!queue.empty()) {
        current = queue.front();
        queue.pop_front();

        for (i = adj[current].begin(); i != adj[current].end(); ++i) {
            if (!visited[*i])
            {
                prev[*i] = current;
                visited[*i] = true;
                if(*i == t) {
                    
                    std::cout << "Found" << std::endl;
                    displayPath(t);
                    exit(0);
                    
                }
                queue.push_back(*i);
            }
        }
    }

    delete [] visited;

}

void Graph::displayPath(int f) {

    int p = f;
    int q;
    std::ptrdiff_t pos;

    int pathLen = 0;
    std::cout << "Path is: ";

    while(p != -1) {

        std::cout << "->" << p;
        q = prev[p];
        if (q != -1) {
            pos = find(adj[p].begin(), adj[p].end(), q) - adj[p].begin();
            pathLen = pathLen + wgt[p].at(pos);
        }
        p = q;

    }

    std::cout << std::endl;
    std::cout << "Path Length: " << pathLen;
    std::cout << std::endl;
}

void Graph::init(int V_) {
    
    this->V = V_;
    adj = new std::vector<int>[V_];
    wgt = new std::vector<int>[V_];
    prev = new int[V_];
    
}

int main() {

    std::cout << "Enter 1 for input data through the console or 2 for input data from file: ";
    size_t choice; std::cin >> choice;

    Graph g;

    if (choice == 1) {

        int n, e;

        std::cout << "Number of vertices: ";
        std::cin >> n;
        std::cout << "Number of edges: ";
        std::cin >> e;

        g.init(n);

        int a, b, c, vStart, vEnd;

        std::cout << "Enter the list of edges in the format \"v1 v2 weight\": ";
        for (size_t i = 0; i < e; ++i) {
            std::cin >> a >> b >> c;
            g.addEdge(a, b, c);
        }

        std::cout << "Enter the start vertex: ";
        std::cin >> vStart;
        std::cout << "Enter the end vertex: ";
        std::cin >> vEnd;

        g.BFS(vEnd, vStart);

    } else if (choice == 2) {

        std::string filename("input.txt");
        std::ifstream file(filename);

        if (file.is_open()) {
            
            int n, e;
            file >> n >> e;
            g.init(n);

            int a, b, c, vStart, vEnd;

            for (size_t i = 0; i < e; ++i) {
                file >> a >> b >> c;
                g.addEdge(a, b, c);
            }

            file >> vStart >> vEnd;
            g.BFS(vEnd, vStart);
            file.close();

        } else {
            std::cout << "Failed to open file.\n";
            return 1;
        }

    } else {
        std::cout << "Invalid number.\n";
        return 1;
    }

    return 0;
    
}
