#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 1e9;  // Represents a very large number

// This function finds the shortest path from start node to all other nodes
void dijkstra(int start, vector<vector<pair<int, int>>> &graph) {
    int n = graph.size();
    vector<int> dist(n, INF); // Start with all distances as infinity
    dist[start] = 0;          // Distance to start is 0

    // Priority queue to pick the nearest node first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // If we found a shorter way before, skip this one
        if (current_distance > dist[current_node])
            continue;

        // Explore all neighbors
        for (auto &neighbor : graph[current_node]) {
            int next_node = neighbor.first;
            int weight = neighbor.second;

            // If there's a quicker way to the next node, update the distance
            if (dist[current_node] + weight < dist[next_node]) {
                dist[next_node] = dist[current_node] + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Shortest distance to node " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> graph(n);

    // Example graph: (node, distance)
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    dijkstra(0, graph);

    return 0;
}

