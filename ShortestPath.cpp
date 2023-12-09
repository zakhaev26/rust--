#pragma once 
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

class Dijkstra {
public:
    using Vertex = char;
    using Weight = int;

    std::unordered_map<Vertex, std::unordered_map<Vertex, Weight>> graph;

    std::unordered_map<Vertex, Weight> run(Vertex start) {
        std::priority_queue<std::pair<Weight, Vertex>, std::vector<std::pair<Weight, Vertex>>, std::greater<>> pq;
        std::unordered_map<Vertex, Weight> distances;

        for (const auto& pair : graph) {
            distances[pair.first] = std::numeric_limits<Weight>::max();
        }

        distances[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            Weight current_distance = pq.top().first;
            Vertex current_vertex = pq.top().second;
            pq.pop();

            if (current_distance > distances[current_vertex]) {
                continue;
            }

            for (const auto& neighbor : graph[current_vertex]) {
                Vertex next_vertex = neighbor.first;
                Weight weight = neighbor.second;
                Weight distance = current_distance + weight;

                if (distance < distances[next_vertex]) {
                    distances[next_vertex] = distance;
                    pq.push({distance, next_vertex});
                }
            }
        }

        return distances;
    }
};

int main() {
    Dijkstra dijkstra;

    int num_edges;
    std::cin >> num_edges;

    std::cout << "Enter the edges in the format (source destination weight):\n";
    for (int i = 0; i < num_edges; ++i) {
        Dijkstra::Vertex source, destination;
        Dijkstra::Weight weight;

        std::cin >> source >> destination >> weight;
        dijkstra.graph[source][destination] = weight;
    }

    Dijkstra::Vertex start_vertex;
    std::cout << "Enter the starting vertex: ";
    std::cin >> start_vertex;

    auto result = dijkstra.run(start_vertex);

    std::cout << "Shortest distances from " << start_vertex << ":\n";
    for (const auto& pair : result) {
        std::cout << "To " << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
