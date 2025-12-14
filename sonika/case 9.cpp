// Case9.cpp
// ATM & Kiosk Maintenance Network using Prim's Algorithm
// Finds Minimum Spanning Tree (MST) to minimize maintenance cost

#include <iostream>
#include <climits>
using namespace std;

#define MAX 10   // Maximum ATMs

// Function to find vertex with minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[MAX][MAX], int V) {
    int totalCost = 0;
    cout << "\nEdge \tCost\n";
    cout << "-----------------\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }

    cout << "-----------------\n";
    cout << "Total Maintenance Cost = " << totalCost << endl;
}

// Prim’s Algorithm Implementation
void primMST(int graph[MAX][MAX], int V) {
    int parent[V];     // Stores MST structure
    int key[V];        // Minimum cost to connect
    bool mstSet[V];    // True if vertex included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from first ATM
    key[0] = 0;
    parent[0] = -1;

    // MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] &&
                !mstSet[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int V = 6; // Number of ATMs

    // Adjacency matrix representing maintenance cost
    int graph[MAX][MAX] = {
        {0, 4, 6, 0, 0, 0},
        {4, 0, 6, 3, 4, 0},
        {6, 6, 0, 1, 2, 0},
        {0, 3, 1, 0, 2, 3},
        {0, 4, 2, 2, 0, 7},
        {0, 0, 0, 3, 7, 0}
    };

    cout << "ATM & Kiosk Maintenance Network\n";
    cout << "Using Prim's Algorithm\n";

    primMST(graph, V);

    return 0;
}

