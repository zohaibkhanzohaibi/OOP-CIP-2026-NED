#include <iostream>
#include <string>
using namespace std;

class Biker {
protected: 
    string bikeModel; 

public:
    Biker(string bike) {
        bikeModel = bike;
        cout << "[Parent 1] Biker: Tuned up the " << bikeModel << endl;
    }

    void rideFast() { 
        cout << ">> " << bikeModel << " is cutting through traffic..." << endl; 
    }
};

class Employee {
protected:
    int employeeID;

public:
    Employee(int id) {
        employeeID = id;
        cout << "[Parent 2] Employee: Logged in as ID #" << employeeID << endl;
    }

    void deliverOrder() { 
        cout << ">> Order Delivered successfully by ID #" << employeeID << endl; 
    }
};

class FoodPandaRider : public Biker, public Employee {
private:
    string riderName;

public:
    // We get 3 inputs: Name (for Child), Bike (for Parent 1), ID (for Parent 2)
    FoodPandaRider(string name, string bike, int id) 
        : Biker(bike), Employee(id) 
    {
        riderName = name;
        cout << "[Child] FoodPandaRider: " << riderName << " is ready for duty!" << endl;
    }

    void complaint() {
        cout << "\n--- CUSTOMER COMPLAINT ---" << endl;
        // Using methods from both parents
        rideFast();      
        deliverOrder(); 
        
        // Using variables from parents (because they are 'protected')
        cout << "Rider (" << riderName << ") says: Boss location ghalat thi!" << endl;
        cout << "Machine: " << bikeModel << " | Emp ID: " << employeeID << endl;
    }
};

int main() {
    cout << "--- SHIFT START ---" << endl;
    
    FoodPandaRider rider("Shapater Boy", "Modified CD-70", 101);

    rider.complaint();

    return 0;
}