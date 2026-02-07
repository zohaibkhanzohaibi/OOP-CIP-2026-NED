#include <iostream>
#include <string>
using namespace std;

// --- Parent Class ---
class Vehicle {
private:
    string brand;
    int modelYear;

public:
    Vehicle(string b, int year) {
        brand = b;
        modelYear = year;
        cout << "Parent Constructor: Vehicle Frame Assembled (" << brand << ")" << endl;
    }

    ~Vehicle() {
        cout << "Parent Destructor: Vehicle Frame Crushed." << endl;
    }

    string getBrand() { return brand; }
    int getYear() { return modelYear; }

    void setYear(int newYear) {
        if(newYear > 1900) modelYear = newYear;
    }

    void displayBasicInfo() {
        cout << "Vehicle Info: " << brand << " (" << modelYear << ")" << endl;
    }
};

// --- Child Class ---
class HondaCivic : public Vehicle {
private:
    string trimLevel; 

public:
    //parent constructor is called first
    HondaCivic(string b, int year, string trim) : Vehicle(b, year) { 
        trimLevel = trim;
        cout << "Child Constructor: Installing Civic features (" << trimLevel << ")" << endl;
    }

    ~HondaCivic() {
        cout << "Child Destructor: Removing Civic Accessories." << endl;
    }

    void showFullSpecs() {
        cout << "\n--- Full Car Specs ---" << endl;
        cout << "Make: " << getBrand() << endl; 
        cout << "Year: " << getYear() << endl;
        cout << "Trim: " << trimLevel << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    HondaCivic myCar("Honda", 2024, "RS Turbo");
    
    myCar.showFullSpecs();
    
    cout << "\n>>> Car is reaching end of life..." << endl;
}