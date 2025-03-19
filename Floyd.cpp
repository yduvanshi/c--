#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Define infinity

void floydWarshall(vector<vector<int>>& dist, int V) {
    // Step 1: Initialize the distance matrix
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Step 2: Update the distance matrix
                if (dist[i][k] != INF && dist[k][j] != INF) { // Check for overflow
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int V = 4; // Number of vertices
    vector<vector<int>> dist = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    cout<<"namste";

    floydWarshall(dist, V);

    // Print the shortest distance matrix
    cout << "The shortest distance matrix is:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}