// hierarchical inheritance, access specifiers
#include <iostream>
#include <string>
using namespace std;

// --- The Parent Class ---
class Father {
public:
    string surname = "Khan";    // Public: Everyone can see this
protected:
    int bankBalance = 50000;    // Protected: Only kids can inherit this
private:
    int atmPin = 1122;          // Private: NO ONE can touch this (not even kids)

public:
    Father() { cout << "[Father] created." << endl; }
};

class PublicSon : public Father {
public:
    void showAccess() {
        cout << "\n--- Public Son Access ---" << endl;
        cout << "Surname: " << surname << endl;      // OK (Public)
        cout << "Balance: " << bankBalance << endl;  // OK (Protected)
        // cout << "PIN: " << atmPin;                // ERROR! Parent's private is inaccessible.
    }
};

class ProtectedSon : protected Father {
public:
    void showAccess() {
        cout << "\n--- Protected Son Access ---" << endl;
        cout << "Surname: " << surname << endl;      // OK (Protected, but I can use it internally)
        cout << "Balance: " << bankBalance << endl;  // OK
    }
    
    // Example: If this son has a child, that child CAN access 'surname'
    // because it is now 'protected', not 'private'.
};

class PrivateSon : private Father {
public:
    void showAccess() {
        cout << "\n--- Private Son Access ---" << endl;
        cout << "Surname: " << surname << endl;     // OK (I can use it internally)
        cout << "Balance: " << bankBalance << endl; // OK (I can use it internally)
    }
};

// --- GrandChild to prove Private Inheritance stops the flow ---
class GrandChild : public PrivateSon {
public:
    void tryToAccess() {
        // cout << surname;      // ERROR! PrivateSon made 'surname' private to himself.
        // cout << bankBalance;  // ERROR! The chain is broken.
        cout << "Grandchild gets nothing from Grandfather." << endl;
    }
};


int main() {
    PublicSon ali;
    ali.showAccess();
    cout << "Main sees Ali's Surname: " << ali.surname << endl; // OK (It is still public)

    ProtectedSon bilal;
    bilal.showAccess();

    PrivateSon danish;
    danish.showAccess();

    return 0;
}