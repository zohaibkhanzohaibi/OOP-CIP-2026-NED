#include <iostream>
#include <string>

using namespace std;

class NPC {
private:
    string name;
    int health;
    int* xp; // Dynamically allocated to demonstrate the Destructor

public:
    // 1. Default Constructor
    NPC() {
        // TODO 
    }

    // 2. Parameterized Constructor
    NPC(std::string npcName, int npcHealth, int startingXp) {
        // TODO
    }

    // 3. Destructor (Cleans up the memory allocated for xp)
    ~NPC() {
        delete xp; 
        std::cout << "[Despawn] " << name << " has been removed from the game memory.\n";
    }

    // 4. Getter and Setter for Health
    void setHealth(int h) {
        if (h >= 0) health = h;
    }

    int getHealth() const {
        return health;
    }

    // 5. The "Useful Function" (Work: Taking Damage logic)
    void takeDamage(int damage) {
        health -= damage;
        std::cout << name << " took " << damage << " damage! ";
        
        if (health <= 0) {
            health = 0;
            std::cout << "Target neutralized.\n";
        } else {
            std::cout << "Remaining Health: " << health << "\n";
        }
    }
};

int main() {
    // Creating an NPC using the parameterized constructor
    NPC guard("Captain Aegis", 150, 500);

    // Using the "work" function
    guard.takeDamage(40);
    guard.takeDamage(120);

    // Using Getter/Setter
    cout << "Final check on health: " << guard.getHealth() << "\n";

    return 0; // Destructor is automatically called here for 'guard'
}