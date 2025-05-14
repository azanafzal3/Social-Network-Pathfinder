#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <stack>

using namespace std;

// Graph banane ka function
void createGraph(const string& filename, unordered_map<int, vector<pair<int, int>>>& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int user1, user2, weight;
        ss >> user1 >> user2 >> weight;

        // Add edges to the graph
        graph[user1].emplace_back(user2, weight);
        graph[user2].emplace_back(user1, weight); // Undirected graph ke liye
    }

    cout << "Graph successfully created." << endl;
    file.close();
}

// Heuristic function: h(n) = kisi node ke direct connections ki taadaad
int heuristic(const unordered_map<int, vector<pair<int, int>>>& graph, int node) {
    return graph.at(node).size();
}

// A* Algorithm jo shortest path find karega
void aStar(const unordered_map<int, vector<pair<int, int>>>& graph, int start, int goal) {
     // Priority queue use karte hain: {f(n), node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Distance map banayein jo g(n) track karega
    unordered_map<int, int> gCost;
    for (const auto& node : graph) {
        gCost[node.first] = numeric_limits<int>::max();
    }
    gCost[start] = 0;

// Parent map jo path reconstruct karne ke kaam aayega
    unordered_map<int, int> parent;
    parent[start] = -1; // Start node has no parent

    // Start node ko queue me daal dein
    pq.emplace(heuristic(graph, start), start);

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        // Check if we reached the goal
        if (current == goal) {
            // Reconstruct the path
            stack<int> path;
            int node = goal;
            while (node != -1) {
                path.push(node);
                node = parent[node];
            }

          
            cout << "Shortest Path: ";
            while (!path.empty()) {
                cout << path.top();
                path.pop();
                if (!path.empty()) cout << " -> ";
            }
            cout << endl;

           
            cout << "Total Cost: " << gCost[goal] << endl;
            return;
        }

        // Process neighbors
        for (const auto& neighbor : graph.at(current)) {
            int neighborNode = neighbor.first;
            int edgeWeight = neighbor.second;

            // Calculate tentative g(n)
            int tentativeG = gCost[current] + edgeWeight;

            // Update if a shorter path is found
            if (tentativeG < gCost[neighborNode]) {
                gCost[neighborNode] = tentativeG;
                int fCost = tentativeG + heuristic(graph, neighborNode);
                pq.emplace(fCost, neighborNode);
                parent[neighborNode] = current; // Update parent
            }
        }
    }

    cout << "No path found from " << start << " to " << goal << "." << endl;
}

int main() {
    string filename = "social-network-proj-graph.txt";

    // Graph representation: adjacency list
    unordered_map<int, vector<pair<int, int>>> graph;

   
    createGraph(filename, graph);

   
int startNode, goalNode;


do {
    cout << "Enter the source node (non-negative): ";
    cin >> startNode;

    if (cin.fail() || startNode < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a non-negative integer." << endl;
    }
} while (cin.fail() || startNode < 0);


do {
    cout << "Enter the destination node (non-negative): ";
    cin >> goalNode;

    if (cin.fail() || goalNode < 0) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a non-negative integer." << endl;
    }
} while (cin.fail() || goalNode < 0);



   
    aStar(graph, startNode, goalNode);

    return 0;
}
