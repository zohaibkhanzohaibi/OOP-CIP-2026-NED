#include <iostream>
#include <string>
/* TODO: 1. Include the library required for File Input/Output (fstream) */

using namespace std;

// --- FUNCTION PROTOTYPES ---
void updateBookPrice(double *pricePtr, double newPrice);
int calculateLateFees(int days); // Recursive function

int main() {
    // 1. BASIC VARIABLES & POINTERS
    string bookTitle = "C++ Mastery";
    double bookPrice = 50.0;
    double *pPrice = &bookPrice;

    // 2. SWITCH CASE: User Menu
    int choice;
    cout << "--- Library Management System ---" << endl;
    cout << "1. Update Price\n2. Calculate Late Fees\n3. Save Data\nEnter choice: ";
    cin >> choice;

    /* TODO: 2. Implement a Switch Case for 'choice' */
    // Case 1: Call updateBookPrice and pass pPrice and a new value (e.g., 65.0)
    // Case 2: Ask for late days and call calculateLateFees()
    // Default: Print "Invalid Selection"

    // 3. RECURSION: Late Fee Calculation
    // Logic: Fee is $2 for the first day, and doubles every day after.
    // (Example: Day 1=2, Day 2=4, Day 3=8...)
    
    // 4. DYNAMIC MEMORY & LOOPS
    int memberCount;
    cout << "\nHow many members to register? ";
    cin >> memberCount;

    /* TODO: 3. Dynamically allocate an array for member IDs of size 'memberCount' */

    /* TODO: 4. Use a 'for' loop to take input for each member ID */

    // 5. FILE HANDLING: Saving Member List
    /* TODO: 5. Create an output file stream object (ofstream) named 'outFile' 
       and open a file named "members.txt" */

    if (/* TODO: 6. Check if outFile is successfully open */) {
        outFile << "Registered Member IDs:" << endl;
        for (int i = 0; i < memberCount; i++) {
            outFile << "ID: " << memberIDs[i] << endl;
        }
        /* TODO: 7. Close the file stream */
        cout << "Data saved to members.txt successfully." << endl;
    } else {
        cout << "Error opening file!" << endl;
    }

    // 6. CLEANUP
    /* TODO: 8. Deallocate the dynamic array memory */

    return 0;
}

// --- FUNCTION DEFINITIONS ---

void updateBookPrice(double *pricePtr, double newPrice) {
    /* TODO: 9. Use the dereference operator to update the price */
    cout << "Price updated successfully to $" << *pricePtr << endl;
}

/* TODO: 10. Complete the Recursive Function */
int calculateLateFees(int days) {
    // Base Case: If days is 1, return 2
    if (days <= 1) {
        return 2;
    }
    // Recursive Step: return 2 * calculateLateFees(days - 1)
    return 2 * calculateLateFees(days - 1);
}