#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adj;
    vector<bool> visited;

    void DFSUtil(int v) {
        visited[v] = true;

        // Print current node
        cout << char(v + 'A') << " ";

        // Visit all adjacent vertices
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor);
            }
        }
    }

public:
    Graph(int v) {
        vertices = v;
        adj.resize(v);
        visited.resize(v, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int start) {
        cout << "DFS Traversal Order: ";
        DFSUtil(start);
        cout << endl;
    }
};

int main() {
    Graph g(7);

    // A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6

    // A: C B D
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(0, 3);

    // B: A C E G
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 6);

    // C: A B D
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 3);

    // D: C A
    g.addEdge(3, 2);
    g.addEdge(3, 0);

    // E: G F B
    g.addEdge(4, 6);
    g.addEdge(4, 5);
    g.addEdge(4, 1);

    // F: G E
    g.addEdge(5, 6);
    g.addEdge(5, 4);

    // G: F B
    g.addEdge(6, 5);
    g.addEdge(6, 1);

    // Start DFS from A
    g.DFS(0);

    return 0;
}