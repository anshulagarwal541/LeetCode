#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> map;
        
        // Construct the graph
        for (int x = 0; x < edges.size(); x++) {
            map[edges[x][0]].push_back({edges[x][1], succProb[x]});
            map[edges[x][1]].push_back({edges[x][0], succProb[x]});
        }

        // Priority queue to keep track of maximum probability path
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0); // Store maximum probability to each node
        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});
        
        // BFS with priority queue
        while (!pq.empty()) {
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            // Early stopping if reached end_node
            if (currNode == end_node) {
                return currProb;
            }

            for (auto& neighbor : map[currNode]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                
                // If we found a path with a higher probability, update it
                if (currProb * edgeProb > maxProb[nextNode]) {
                    maxProb[nextNode] = currProb * edgeProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }
        
        return 0.0; // If no path is found
    }
};
