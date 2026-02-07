//predict the output without running the code
#include <iostream>
#include <string>

using namespace std;

class Trace {
public:
    string name;
    Trace(string n) : name(n) { 
        cout << "Constructing " << name << endl; 
    }

    ~Trace() { cout << "Destructing " << name << endl; }
};

void func(Trace t) { 
    cout << "Inside function" << endl;
}

int main() {
    Trace t1("Object1");
    func(t1);
    cout << "Back in main" << endl;
    return 0;
}