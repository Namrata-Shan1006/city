// Case2_UrbanForest.cpp
// Urban Forest & Green Coverage Management using HASHING
// C++17 | Simple, readable, large-scale ready

#include <bits/stdc++.h>
using namespace std;

// ---------------- TREE STRUCT ----------------
struct Tree {
    int treeID;
    string species;
    string zone;
    int healthScore;          // 0–100
    double carbonAbsorption;  // kg/year
};

// ---------------- HASH TABLE ----------------
class ForestHashTable {
private:
    unordered_map<int, Tree> table;

public:
    // Insert or Update tree
    void addTree(int id, string species, string zone, int health, double carbon) {
        Tree t;
        t.treeID = id;
        t.species = species;
        t.zone = zone;
        t.healthScore = health;
        t.carbonAbsorption = carbon;

        table[id] = t;
        cout << "Tree " << id << " added/updated successfully.\n";
    }

    // Search tree by ID
    void searchTree(int id) {
        if (table.find(id) == table.end()) {
            cout << "Tree ID " << id << " NOT FOUND.\n";
            return;
        }

        Tree t = table[id];
        cout << "\n--- TREE DETAILS ---\n";
        cout << "Tree ID: " << t.treeID << "\n";
        cout << "Species: " << t.species << "\n";
        cout << "Zone   : " << t.zone << "\n";
        cout << "Health : " << t.healthScore << "\n";
        cout << "Carbon : " << t.carbonAbsorption << " kg/year\n";
    }

    // Display all trees
    void displayAll() {
        cout << "\n===== ALL TREES =====\n";
        for (auto &pair : table) {
            Tree t = pair.second;
            cout << t.treeID << " | " << t.species << " | "
                 << t.zone << " | " << t.healthScore << " | "
                 << t.carbonAbsorption << "\n";
        }
    }

    // Count trees
    int countTrees() {
        return table.size();
    }
};

// ---------------- MAIN ----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ForestHashTable forest;

    // Sample insertions (simulating CSV load)
    forest.addTree(101, "Neem", "Zone-A", 85, 22.5);
    forest.addTree(102, "Peepal", "Zone-B", 90, 30.2);
    forest.addTree(103, "Banyan", "Zone-A", 88, 40.1);
    forest.addTree(104, "Mango", "Zone-C", 70, 18.9);
    forest.addTree(105, "Ashoka", "Zone-D", 92, 25.4);

    // Search
    forest.searchTree(103);
    forest.searchTree(999);   // not found

    // Display
    forest.displayAll();

    cout << "\nTotal Trees Managed: " << forest.countTrees() << "\n";

    return 0;
}

