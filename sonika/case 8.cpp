// ===============================
// Public Library Management System
// Algorithm Used: Binary Search
// Language: C++17
// ===============================

#include <bits/stdc++.h>
using namespace std;

// Structure to store Book details
struct Book {
    int bookID;
    string title;
    string author;
};

// Binary Search function
int binarySearch(vector<Book>& books, int targetID) {
    int low = 0;
    int high = books.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (books[mid].bookID == targetID)
            return mid;
        else if (books[mid].bookID < targetID)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Sample sorted dataset (Book ID must be sorted)
    vector<Book> library = {
        {101, "Data Structures", "Seymour Lipschutz"},
        {102, "Operating Systems", "Silberschatz"},
        {103, "Computer Networks", "Andrew S. Tanenbaum"},
        {104, "Database Systems", "Ramakrishnan"},
        {105, "Design and Analysis of Algorithms", "CLRS"},
        {106, "Artificial Intelligence", "Stuart Russell"},
        {107, "Machine Learning", "Tom Mitchell"},
        {108, "Compiler Design", "Alfred Aho"},
        {109, "Software Engineering", "Ian Sommerville"},
        {110, "Discrete Mathematics", "Kenneth Rosen"}
    };

    int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    int result = binarySearch(library, searchID);

    if (result != -1) {
        cout << "\n📘 Book Found!\n";
        cout << "Book ID : " << library[result].bookID << "\n";
        cout << "Title   : " << library[result].title << "\n";
        cout << "Author  : " << library[result].author << "\n";
    } else {
        cout << "\n❌ Book not found in library.\n";
    }

    return 0;
}

