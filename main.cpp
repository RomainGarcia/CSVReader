#include "Csv.h"
#include <iostream>

using namespace std;

int main() {

    // Read the CSV file and populate the data map
    vector <map<string, string>> data = Csv::read("example.csv", ';');

    // Loop on each row in the data vector
    for (const auto& line : data) {
        // Loop on each column of the current line
        for (const auto& column : line) {
            cout << column.first << ": " << column.second << endl;
        }

        // Get a specific column for the current line
        string description = line.find("description") != line.end() ? line.at("description") : "Line does not exists";
        cout << "Description: " << description << endl;
    }

    return (0);
}
