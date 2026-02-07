#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int ID;
    string name;
    double cgpa;

public:
    // 1. Default Constructor
    Student() : ID(1), name("student"), cgpa(1.0) {}

    // 2. Full Parameterized Constructor (All values)
    Student(int id, string n, double c) : ID(id), name(n), cgpa(c) {}

    // 3. NEW: Partial Constructor (Only ID)
    // We provide default values for name and cgpa so the object is still valid.
    Student(int id) : ID(id), name("Unknown"), cgpa(0.0) {
        cout << "[System] Student created with ID only. Name and CGPA set to defaults." << endl;
    }

    // --- Getters ---
    int getID() { return ID; }
    string getName() { return name; }
    double getCGPA() { return cgpa; }
};

int main() {
    // Uses Default Constructor
    Student std1;

    // Uses Full Parameterized Constructor
    Student std2(101, "Ahmad", 3.5);

    // Uses the NEW Partial Constructor (Initializing only one value)
    Student std3(505);

    cout << "\n--- Student Report ---" << endl;
    
    cout << "Student 1: " << std1.getName() << " (ID: " << std1.getID() << ")" << endl;
    cout << "Student 2: " << std2.getName() << " (ID: " << std2.getID() << ")" << endl;
    cout << "Student 3: " << std3.getName() << " (ID: " << std3.getID() << ")" << endl;

    return 0;
}