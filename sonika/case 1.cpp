#include <bits/stdc++.h>
using namespace std;

/*
 University Admission & Hostel Allocation System
 Algorithms:
 1) Quick Sort – ranking students by marks
 2) Max Heap – hostel allocation
*/

struct Student {
    int id;
    string name;
    int marks;
};

// ---------------- QUICK SORT ----------------
int partition(vector<Student> &a, int low, int high) {
    int pivot = a[high].marks;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j].marks > pivot) {   // descending order
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<Student> &a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// ---------------- MAX HEAP ----------------
class MaxHeap {
    vector<Student> heap;

public:
    void insert(Student s) {
        heap.push_back(s);
        int i = heap.size() - 1;

        while (i > 0 && heap[(i - 1) / 2].marks < heap[i].marks) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    Student extractMax() {
        Student root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < heap.size() && heap[left].marks > heap[largest].marks)
                largest = left;
            if (right < heap.size() && heap[right].marks > heap[largest].marks)
                largest = right;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
        return root;
    }

    bool empty() {
        return heap.empty();
    }
};

// ---------------- MAIN ----------------
int main() {
    vector<Student> students = {
        {101, "Ananya", 95},
        {102, "Rahul", 88},
        {103, "Meera", 91},
        {104, "Karthik", 78},
        {105, "Priya", 85},
        {106, "Arjun", 92},
        {107, "Sneha", 89}
    };

    int hostelRooms = 4;

    cout << "Sorting students by merit...\n";
    quickSort(students, 0, students.size() - 1);

    MaxHeap heap;
    for (auto &s : students)
        heap.insert(s);

    cout << "\nHostel Allocation:\n";
    while (hostelRooms-- && !heap.empty()) {
        Student s = heap.extractMax();
        cout << "Room Allocated to: "
             << s.name << " (Marks: " << s.marks << ")\n";
    }

    return 0;
}

