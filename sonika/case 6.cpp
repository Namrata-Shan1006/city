#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= RECORD STRUCT =================
struct Record {
    int id;
    string name;
    string type;   // Birth / Death / Marriage
    int year;
};

// ================= DISPLAY FUNCTION =================
void display(const vector<Record>& records) {
    cout << "\nID\tName\t\tType\t\tYear\n";
    cout << "---------------------------------------------\n";
    for (const auto& r : records) {
        cout << r.id << "\t"
             << r.name << "\t\t"
             << r.type << "\t\t"
             << r.year << "\n";
    }
}

// ================= MERGE FUNCTION =================
void merge(vector<Record>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Record> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge based on YEAR (stable)
    while (i < n1 && j < n2) {
        if (L[i].year <= R[j].year) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

// ================= MERGE SORT =================
void mergeSort(vector<Record>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ================= MAIN =================
int main() {
    vector<Record> records = {
        {101,"Ramesh","Birth",1998},
        {102,"Sita","Birth",2001},
        {103,"Amit","Marriage",2018},
        {104,"Kiran","Death",2020},
        {105,"Anjali","Birth",1995},
        {106,"Rohit","Marriage",2015},
        {107,"Meena","Death",2019},
        {108,"Suresh","Birth",2000},
        {109,"Pooja","Marriage",2022},
        {110,"Arun","Birth",1992}
    };

    cout << "=== BEFORE SORTING (Civil Records) ===";
    display(records);

    mergeSort(records, 0, records.size() - 1);

    cout << "\n=== AFTER SORTING BY YEAR (Merge Sort) ===";
    display(records);

    return 0;
}

