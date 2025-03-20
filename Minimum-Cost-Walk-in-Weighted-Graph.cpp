class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform BFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(getComponentCost(
                    node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                answer.push_back(componentCost[components[start]]);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    int getComponentCost(int source, vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited, vector<int>& components,
                         int componentId) {
        queue<int> nodesQueue;
        int componentCost = INT_MAX;

        nodesQueue.push(source);
        visited[source] = true;
        while (!nodesQueue.empty()) {
            int node = nodesQueue.front();
            nodesQueue.pop();
            components[node] = componentId;
            for (auto& [neighbor, weight] : adjList[node]) {
                componentCost &= weight;
                if (visited[neighbor]) continue;
                visited[neighbor] = true;
                nodesQueue.push(neighbor);
            }
        }

        return componentCost;
    }
};