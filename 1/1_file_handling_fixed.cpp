#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 1. This line creates the object AND opens the file.
    ofstream outputFile("example.txt");
	
    // 2. This line tries to open it AGAIN. 
	// This causes the stream to fail. So remove this to work fine.
	//outputFile.open("example.txt");
    if (outputFile.is_open()) {

        // Write data to the file
        outputFile << "Hello, World!" << endl;
        outputFile << 42 << endl;
        outputFile.close(); // Close the file
    }
    else {

        // Failed to open the file
        cout << "Error opening the file for writing."
             << endl;
        return 1;
    }

    // Reading from a file
    ifstream inputFile("example.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            // Print each line
            cout << line << endl;
        }
        // Close the file
        inputFile.close();
    }
    else {

        // Failed to open the file
        cout << "Error opening the file for reading."
             << endl;
        return 1;
    }

    return 0;
}