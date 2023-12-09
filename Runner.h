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
