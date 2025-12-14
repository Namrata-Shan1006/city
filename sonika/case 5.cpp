// food_quality_detection.cpp
// C++17 Program for Food Quality & Contamination Detection
// Algorithm Used: Linear Search
// Purpose: Check if food sample exceeds safety limits

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store contaminant details
struct Contaminant {
    string name;
    double maxPPM;   // Maximum allowed parts per million
};

// Function to check contamination level
// Returns:
//  1  -> Unsafe (limit exceeded)
//  0  -> Safe
// -1  -> Contaminant not found
int checkFoodSafety(const vector<Contaminant>& limits,
                    const string& sampleName,
                    double samplePPM)
{
    // Linear Search through contaminant list
    for (int i = 0; i < limits.size(); i++) {
        if (limits[i].name == sampleName) {
            if (samplePPM > limits[i].maxPPM)
                return 1;   // Unsafe
            else
                return 0;   // Safe
        }
    }
    return -1; // Not found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Dataset loaded (simulating CSV)
    vector<Contaminant> safetyLimits = {
        {"Lead", 0.05},
        {"Mercury", 0.01},
        {"Arsenic", 0.10},
        {"Pesticides", 0.50},
        {"Bacteria", 100.0}
    };

    cout << "=== Food Quality & Contamination Detection System ===\n\n";

    string foodName;
    double ppmValue;

    cout << "Enter contaminant name: ";
    cin >> foodName;

    cout << "Enter detected PPM value: ";
    cin >> ppmValue;

    int result = checkFoodSafety(safetyLimits, foodName, ppmValue);

    cout << "\n--- Inspection Result ---\n";
    if (result == 1) {
        cout << "Status: ❌ UNSAFE\n";
        cout << "Reason: Contaminant level exceeds permitted limit.\n";
    }
    else if (result == 0) {
        cout << "Status: ✅ SAFE\n";
        cout << "Reason: Contaminant level is within safe limits.\n";
    }
    else {
        cout << "Status: ⚠ UNKNOWN\n";
        cout << "Reason: Contaminant not found in database.\n";
    }

    cout << "\nNote:\n";
    cout << "- Linear Search is used due to small dataset size.\n";
    cout << "- For large-scale systems, hashing can improve performance.\n";

    return 0;
}

