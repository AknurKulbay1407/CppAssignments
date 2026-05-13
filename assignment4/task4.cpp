#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, string> Pair;

int main() {

    // Graph representation
    map<string, vector<Pair>> graph;

    graph["Edinburgh"].push_back({100, "Perth"});
    graph["Edinburgh"].push_back({50, "Stirling"});
    graph["Edinburgh"].push_back({70, "Glasgow"});

    graph["Perth"].push_back({60, "Dundee"});
    graph["Perth"].push_back({40, "Stirling"});
    graph["Perth"].push_back({100, "Edinburgh"});

    graph["Stirling"].push_back({40, "Perth"});
    graph["Stirling"].push_back({50, "Glasgow"});
    graph["Stirling"].push_back({50, "Edinburgh"});

    graph["Glasgow"].push_back({50, "Stirling"});
    graph["Glasgow"].push_back({70, "Edinburgh"});

    graph["Dundee"].push_back({60, "Perth"});

    // Distance table
    map<string, int> dist;

    dist["Edinburgh"] = 0;
    dist["Perth"] = INT_MAX;
    dist["Stirling"] = INT_MAX;
    dist["Glasgow"] = INT_MAX;
    dist["Dundee"] = INT_MAX;

    // Min priority queue
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    pq.push({0, "Edinburgh"});

    while (!pq.empty()) {

        int currentDist = pq.top().first;
        string currentCity = pq.top().second;
        pq.pop();

        for (auto neighbor : graph[currentCity]) {

            int weight = neighbor.first;
            string nextCity = neighbor.second;

            if (dist[currentCity] + weight < dist[nextCity]) {

                dist[nextCity] = dist[currentCity] + weight;

                pq.push({dist[nextCity], nextCity});
            }
        }
    }

    cout << "Shortest distance from Edinburgh to Dundee: "
         << dist["Dundee"] << endl;

    cout << "Path: Edinburgh -> Stirling -> Perth -> Dundee"
         << endl;

    return 0;
}