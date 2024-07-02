#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

class BellmanFord {
private:
    int V, E; // Number of vertices and edges
    vector<Edge> edges; // List of edges
    vector<int> dist; // Distance array

public:
    BellmanFord(int v, int e) : V(v), E(e) {
        dist.resize(V, numeric_limits<int>::max()); // Initialize distances to infinity
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    // Function to perform Bellman-Ford algorithm
    bool bellmanFord(int src) {
        dist[src] = 0; // Distance to source vertex is 0

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (const auto& edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int weight = edge.weight;
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative-weight cycles
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                // Negative weight cycle found
                return false;
            }
        }

        return true;
    }

    // Function to print distances from source vertex
    void printDistances(int src) {
        cout << "Vertex\t Distance from Source\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
};

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    BellmanFord graph(V, E);

    // Add edges: (u, v, weight)
    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);

    int src = 0; // Source vertex

    if (graph.bellmanFord(src)) {
        cout << "Shortest distances from source vertex " << src << ":\n";
        graph.printDistances(src);
    } else {
        cout << "Graph contains negative weight cycle\n";
    }

    return 0;
}
