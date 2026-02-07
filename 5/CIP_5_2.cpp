#include <iostream>
using namespace std;

class Sawari {
public:
    void startEngine() { cout << "Engine starting... Ghurr ghurr..." << endl; }
};

// --- Single Inheritance ---
class Bike : public Sawari {
public:
    void wheelie() { cout << "One wheeling at Seaview!" << endl; }
};

// --- Multilevel Inheritance (The Evolution of Rickshaw) ---
// Sawari -> Rickshaw -> Chinchi
class Rickshaw : public Sawari {
public:
    void meterDown() { cout << "Meter kharab hai, 500 lagenge." << endl; }
};

class Chinchi : public Rickshaw {
public:
    void playSongs() { cout << "Playing: 'Mast hua... barbaad hua..' (Full Volume)" << endl; }
};

int main() {
    Chinchi laalPari;
    laalPari.startEngine(); 
    laalPari.meterDown();  
    laalPari.playSongs();   
    
    return 0;
}