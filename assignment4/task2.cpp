#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void bfs(map<char, vector<char>>& graph, char start) {
    set<char> visited;
    queue<char> q;

    visited.insert(start);
    q.push(start);

    cout << "BFS Order: ";

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        cout << node << " ";

        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

int main() {
    map<char, vector<char>> graph;

    graph['A'] = {'C', 'B', 'D'};
    graph['B'] = {'A', 'C', 'E', 'G'};
    graph['C'] = {'A', 'B', 'D'};
    graph['D'] = {'C', 'A'};
    graph['E'] = {'G', 'F', 'B'};
    graph['F'] = {'G', 'E'};
    graph['G'] = {'F', 'B'};

    bfs(graph, 'A');

    return 0;
}