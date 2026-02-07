#include <iostream>
using namespace std;

class Vehicle {
public:
    // VIRTUAL is the key! It enables Late Binding.
    // If you remove 'virtual', everyone will behave like a generic Vehicle.
    virtual void reactToSignal() {
        cout << "Vehicle stopping slowly..." << endl;
    }
    
    virtual ~Vehicle() {} // Virtual Destructor is a MUST
};

class Civic : public Vehicle {
public:
    void reactToSignal() override {
        cout << "Civic: Stops quietly behind the line." << endl;
    }
};

class W11_Bus : public Vehicle {
public:
    void reactToSignal() override {
        cout << "W-11: Breaks signal! 'Jane de ustad!'" << endl;
    }
};

int main() {
    Vehicle* trafficLane[2];
    
    trafficLane[0] = new Civic();
    trafficLane[1] = new W11_Bus();

    cout << "--- Traffic Light Turns RED ---" << endl;
    
    for(int i=0; i<2; i++) {
        // Without 'virtual', both would say "Vehicle stopping slowly..."
        trafficLane[i]->reactToSignal(); 
    }

    // Cleanup
    delete trafficLane[0];
    delete trafficLane[1];
    
    return 0;
}