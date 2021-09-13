#include "Csv.h"
#include <iostream>

using namespace std;

int main() {

    // Read the CSV file and populate the data map
    std::vector <std::map<std::string, std::string>> data = Csv::read("example.csv", ';');

    // Loop on each row in the data vector
    for (const auto& line : data) {
        // Loop on each column of the current line
        for (const auto& column : line) {
            std::cout << column.first << ": " << column.second << endl;
        }

        // Get a specific column for the current line
        std::string description = line.find("description") != line.end() ? line.at("description") : "Line does not exists";
        std::cout << "Description: " << description << std::endl;
    }

    return (0);
}
