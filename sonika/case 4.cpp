// land_record_system.cpp
// C++17 - Land Record Digitization using Binary Search
// Features:
// - Structured land record storage
// - Sorted dataset
// - Fast record lookup using Binary Search
// - User-friendly output

#include <bits/stdc++.h>
using namespace std;

// ---------------------- STRUCTURE ----------------------
struct LandRecord {
    int propertyID;
    string ownerName;
    string location;
    double area;      // in square meters
    double landValue; // in lakhs
};

// ---------------------- BINARY SEARCH ----------------------
int binarySearch(const vector<LandRecord>& records, int targetID) {
    int low = 0, high = records.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (records[mid].propertyID == targetID)
            return mid;
        else if (records[mid].propertyID < targetID)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

// ---------------------- DISPLAY RECORD ----------------------
void displayRecord(const LandRecord& rec) {
    cout << "\n----- LAND RECORD FOUND -----\n";
    cout << "Property ID : " << rec.propertyID << "\n";
    cout << "Owner Name : " << rec.ownerName << "\n";
    cout << "Location   : " << rec.location << "\n";
    cout << "Area       : " << rec.area << " sq.m\n";
    cout << "Land Value : ₹" << rec.landValue << " lakhs\n";
}

// ---------------------- MAIN ----------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ---------------- DATASET (SORTED) ----------------
    vector<LandRecord> landDB = {
        {101, "Ramesh Patil", "Hubballi", 240.5, 45.2},
        {104, "Anita Desai", "Dharwad", 180.0, 32.8},
        {109, "Suresh Kulkarni", "Belagavi", 300.2, 58.4},
        {115, "Meena Joshi", "Hubballi", 150.0, 29.1},
        {121, "Rahul Shetty", "Bengaluru", 400.8, 95.6},
        {128, "Kavita Naik", "Mysuru", 210.4, 41.0},
        {135, "Amit Rao", "Udupi", 175.6, 36.9},
        {142, "Sunita Hegde", "Karwar", 260.7, 52.3},
        {150, "Vijay Patwardhan", "Pune", 500.0, 120.0},
        {165, "Neha Malhotra", "Mumbai", 350.9, 210.5}
    };

    cout << "===== LAND RECORD DIGITIZATION SYSTEM =====\n";
    cout << "Total Records Available: " << landDB.size() << "\n";

    int searchID;
    cout << "\nEnter Property ID to search: ";
    cin >> searchID;

    int index = binarySearch(landDB, searchID);

    if (index != -1)
        displayRecord(landDB[index]);
    else
        cout << "\n❌ Record NOT found for Property ID " << searchID << "\n";

    cout << "\nSystem executed successfully.\n";
    return 0;
}

