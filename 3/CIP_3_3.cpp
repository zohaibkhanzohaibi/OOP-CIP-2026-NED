#include <iostream>
#include <string>

using namespace std;

class NPC {
private:
    string name;
    int* powerLevel; // Pointer to dynamic memory

public:
    // Parameterized Constructor
    NPC(string name, int power) {
        this->name = name;
        this->powerLevel = new int(power);
        cout << "[System] " << this->name << " initialized with Power: " << *powerLevel << endl;
    }

    // --- TASK 1: THE DESTRUCTOR ---
    // Rule: Always clean up what you 'new'
    ~NPC() {
        /* YOUR CODE HERE: Delete the powerLevel pointer */
    }

    // --- TASK 2: THE DEEP COPY CONSTRUCTOR ---
    // This should create a BRAND NEW memory address for powerLevel
    // so the clone is independent.
    NPC(const NPC& other) {
        this->name = other.name + " (Clone)";
        
        /* YOUR CODE HERE: 
           1. Allocate new memory for this->powerLevel
           2. Assign the VALUE from other.powerLevel to this new memory 
        */
        
        cout << "[System] Deep Copy created: " << this->name << endl;
    }

    // Function to change power
    void setPower(int p) {
        *(this->powerLevel) = p;
    }

    void display() {
        cout << name << " | Power Address: " << powerLevel << " | Value: " << *powerLevel << endl;
    }
};

int main() {
    // 1. Create original NPC
    NPC* original = new NPC("Blaze", 100);

    // 2. Create a clone using the Copy Constructor
    // This will trigger the code you write in Task 2
    NPC* clone = new NPC(*original);

    cout << "\n--- Before Modification ---" << endl;
    original->display();
    clone->display();

    // 3. Modify the clone's power
    cout << "\n--- After Clone Levels Up ---" << endl;
    clone->setPower(500);

    original->display();
    clone->display();

    // Cleanup
    delete original;
    delete clone;

    return 0;
}