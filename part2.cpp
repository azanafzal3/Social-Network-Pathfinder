#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Graph and Influence structures
unordered_map<int, vector<int>> graph;
unordered_map<int, int> influenceScores;
unordered_map<int, vector<int>> memoPaths;
unordered_map<int, int> memoLengths;

// Parse graph file
void parseGraph(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open graph file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int user1, user2, weight;
        ss >> user1 >> user2 >> weight;

        graph[user1].push_back(user2);
        graph[user2].push_back(user1); // If the graph is undirected
    }

    file.close();
}

// Parse influence scores file
void parseInfluence(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open influence scores file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int user, score;
        ss >> user >> score;

        influenceScores[user] = score;
    }

    file.close();
}

// DP Function to find the longest path starting from a node
pair<int, vector<int>> findLongestPath(int node) {
    if (memoLengths.count(node)) {
        return {memoLengths[node], memoPaths[node]};
    }

    int maxLength = 1;
    vector<int> bestPath = {node};

    for (int neighbor : graph[node]) {
        if (influenceScores[neighbor] > influenceScores[node]) {
            auto [length, path] = findLongestPath(neighbor);
            if (length + 1 > maxLength) {
                maxLength = length + 1;
                bestPath = {node};
                bestPath.insert(bestPath.end(), path.begin(), path.end());
            }
        }
    }

    memoLengths[node] = maxLength;
    memoPaths[node] = bestPath;

    return {maxLength, bestPath};
}

int main() {
    string graphFile = "social-network-proj-graph.txt";
    string influenceFile = "social-network-proj-Influences.txt";

    // Parse files
    parseGraph(graphFile);
    parseInfluence(influenceFile);

    int maxLength = 0;
    vector<int> longestPath;

    // Find the longest path starting from each node
    for (const auto &[node, _] : influenceScores) {
        auto [length, path] = findLongestPath(node);
        if (length > maxLength) {
            maxLength = length;
            longestPath = path;
        }
    }

    // Output results
    cout << "Maximum length of influence chain: " << maxLength << endl;
    cout << "Longest path: ";
    for (size_t i = 0; i < longestPath.size(); ++i) {
        cout << longestPath[i];
        if (i < longestPath.size() - 1) cout << " -> ";
    }
    cout << endl;

    return 0;
}