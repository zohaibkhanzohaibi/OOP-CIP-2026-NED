// this keyword and -> operator example and memmber initialization list
#include <iostream>
#include <string>

// Using namespace std as requested
using namespace std;

class NPC {
private:
    string name;
    int health;

public:
    // Parameterized Constructor using 'this' keyword
    NPC(string name, int health) {
        // 'this->name' refers to the class member
        // 'name' refers to the parameter passed to the constructor
        this->name = name;
        this->health = health;
        cout << "[Spawn] " << this->name << " created with " << this->health << " HP." << endl;
    }

    NPC(string names, int health) : name(names), health(health){
        // Even with the initializer list, we can still use 'this' 
        // inside the body for logic or printing.
        cout << "[Spawn] " << this->name << ") has entered the game." << endl;
    }

    // Destructor
    ~NPC() {
        cout << "[Despawn] " << this->name << " is being cleaned up from memory." << endl;
    }

    // A function using 'this' to show current object context
    void showStatus() {
        cout << "NPC Name: " << this->name << " | Health: " << this->health << endl;
    }

    // Getter for health
    int getHealth() {
        return this->health;
    }
};

int main() {
    const int squadSize = 3;

    // 1. Create an array of NPC pointers
    // This allocates space for 3 memory addresses, but not the objects themselves yet.
    NPC* squad[squadSize];

    // 2. Use 'new' to instantiate objects into the pointer array
    cout << "--- Initializing Squad ---" << endl;
    squad[0] = new NPC("Archer", 80);
    squad[1] = new NPC("Warrior", 150);
    squad[2] = new NPC("Mage", 60);
    cout << "--------------------------" << endl;

    // 3. Accessing member functions using the arrow operator (->)
    cout << "\n--- Squad Status Report ---" << endl;
    for (int i = 0; i < squadSize; i++) {
        squad[i]->showStatus();
    }

    // 4. Memory Management: Deleting the objects
    // Since we used 'new', we MUST use 'delete' for each pointer to avoid memory leaks.
    cout << "\n--- Deleting Squad (Cleaning Memory) ---" << endl;
    for (int i = 0; i < squadSize; i++) {
        delete squad[i]; // This triggers the Destructor for each NPC
    }

    return 0;
}