#include "Csv.h"
#include <iostream>
#include <fstream>
#include <sstream>


std::vector <std::map<std::string, std::string>> Csv::read(const std::string& file, const char delimiter) {

    std::string line, columnName;
    std::vector <std::map<std::string, std::string>> result;
    int columnIndex = 0;

    std::ifstream myFile(file);
    if (myFile.good()) {
        // Extract the first line in the file
        std::getline(myFile, line);

        // Create a string stream from line
        std::stringstream ss(line);

        // Create a temporary map for the column names in order to create a map file containing each column name as key
        std::map<int, std::string> columns;

        // Extract each column name
        while (std::getline(ss, columnName, delimiter)) {
            columns.emplace(columnIndex, columnName);
            ++columnIndex;
        }

        // Extract other lines
        std::map <std::string, std::string> lineResult;
        std::string value;
        while (!myFile.eof()) {
            lineResult.clear();
            std::getline(myFile, line);
            std::stringstream ss2(line);
            columnIndex = 0;
            // Add data if the line is not empty
            if (!ss2.str().empty()) {
                while (std::getline(ss2, value, ';')) {
                    std::string currentColumnName = columns.find(columnIndex) != columns.end() ? columns.at(columnIndex) : "None";
                    lineResult.emplace(currentColumnName, value);
                    ++columnIndex;
                }
                result.emplace_back(lineResult);
            }
        }

        // Close file
        myFile.close();
    } else {
        std::cout << "Unable to open the CSV file: " << file << std::endl;
    }

    return result;
}