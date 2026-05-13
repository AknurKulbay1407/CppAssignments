#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

void dfs(char node, map<char, vector<char>>& graph, set<char>& visited) {
    visited.insert(node);
    cout << node << " ";

    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited);
        }
    }
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

    set<char> visited;

    cout << "DFS Order: ";
    dfs('A', graph, visited);

    return 0;
}