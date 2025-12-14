// =======================================================
// Case7.cpp
// E-Governance Smart Queue Management System
// Algorithm: MAX HEAP
// Language: C++ (DAA Friendly)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

// ---------------- Citizen Structure ----------------
struct Citizen {
    int id;
    string name;
    int priority; 
    // Higher number = higher priority
};

// ---------------- Max Heap Class ----------------
class SmartQueue {
private:
    vector<Citizen> heap;

    // Heapify UP (after insertion)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index].priority > heap[parent].priority) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify DOWN (after removal)
    void heapifyDown(int index) {
        int size = heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left].priority > heap[largest].priority)
                largest = left;

            if (right < size && heap[right].priority > heap[largest].priority)
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insert new citizen
    void addCitizen(int id, string name, int priority) {
        heap.push_back({id, name, priority});
        heapifyUp(heap.size() - 1);
        cout << "Citizen added: " << name 
             << " | Priority: " << priority << endl;
    }

    // Serve next citizen
    void serveCitizen() {
        if (heap.empty()) {
            cout << "No citizens in queue.\n";
            return;
        }

        Citizen top = heap[0];
        cout << "\nNow Serving:\n";
        cout << "ID: " << top.id 
             << " | Name: " << top.name 
             << " | Priority: " << top.priority << endl;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Display current queue
    void displayQueue() {
        cout << "\nCurrent Queue (Heap Order):\n";
        for (auto &c : heap) {
            cout << "ID: " << c.id 
                 << ", Name: " << c.name 
                 << ", Priority: " << c.priority << endl;
        }
    }

    // Check if empty
    bool isEmpty() {
        return heap.empty();
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SmartQueue sq;

    // Sample data (Huge realistic sample)
    sq.addCitizen(101, "Ramesh", 2);   // Normal
    sq.addCitizen(102, "Suresh", 5);   // Senior citizen
    sq.addCitizen(103, "Anita", 4);    // Pregnant woman
    sq.addCitizen(104, "Mahesh", 1);   // General
    sq.addCitizen(105, "Lakshmi", 6);  // Emergency
    sq.addCitizen(106, "Rahul", 3);    // Working professional

    sq.displayQueue();

    // Serving citizens
    cout << "\n--- Serving Process ---\n";
    while (!sq.isEmpty()) {
        sq.serveCitizen();
    }

    cout << "\nAll citizens served successfully.\n";
    return 0;
}

