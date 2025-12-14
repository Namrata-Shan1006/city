// ------------------------------------------------------------
// Agriculture & Irrigation Network Management
// Algorithm: Disjoint Set Union (Union-Find)
// Language : C++17
// ------------------------------------------------------------
// This program manages irrigation connectivity between fields.
// It supports:
// 1. Connecting two fields (channels built)
// 2. Checking if two fields share water
// 3. Finding number of irrigation zones
// 4. Listing all connected irrigation groups
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- DSU CLASS ----------------
class DSU {
private:
    vector<int> parent;   // parent[i] = representative of i
    vector<int> size;     // size of each component

public:
    // Constructor
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        // Initially, every field is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // FIND operation with path compression
    int find(int x) {
        if (parent[x] == x)
            return x;

        // Path compression
        return parent[x] = find(parent[x]);
    }

    // UNION operation (by size)
    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return; // already connected

        // Attach smaller tree to bigger tree
        if (size[rootA] < size[rootB])
            swap(rootA, rootB);

        parent[rootB] = rootA;
        size[rootA] += size[rootB];
    }

    // Check if two fields are connected
    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    // Get size of irrigation zone
    int zoneSize(int x) {
        return size[find(x)];
    }

    // Get all irrigation zones
    map<int, vector<int>> getAllZones() {
        map<int, vector<int>> zones;

        for (int i = 0; i < parent.size(); i++) {
            int root = find(i);
            zones[root].push_back(i);
        }
        return zones;
    }
};

// ---------------- MAIN PROGRAM ----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalFields = 10;   // Example: 10 fields
    DSU irrigation(totalFields);

    // Sample irrigation connections (from dataset)
    vector<pair<int,int>> channels = {
        {0,1}, {1,2}, {2,3}, {3,4},
        {5,6}, {6,7},
        {8,9}
    };

    // Build irrigation channels
    for (auto &c : channels) {
        irrigation.unite(c.first, c.second);
    }

    // Connectivity checks
    cout << "Is field 0 connected to field 4? ";
    cout << (irrigation.connected(0,4) ? "YES\n" : "NO\n");

    cout << "Is field 0 connected to field 7? ";
    cout << (irrigation.connected(0,7) ? "YES\n" : "NO\n");

    // Zone size
    cout << "Size of irrigation zone containing field 3: ";
    cout << irrigation.zoneSize(3) << "\n";

    // Display all irrigation zones
    auto zones = irrigation.getAllZones();
    cout << "\nIrrigation Zones:\n";
    for (auto &z : zones) {
        cout << "Zone Root " << z.first << " : ";
        for (int field : z.second)
            cout << field << " ";
        cout << "\n";
    }

    cout << "\nNote:\n";
    cout << "- DSU supports fast merging & connectivity checks\n";
    cout << "- It does NOT support splitting irrigation zones\n";

    return 0;
}

