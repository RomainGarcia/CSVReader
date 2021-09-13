#include "Csv.h"
#include <iostream>
#include <fstream>
#include <sstream>


vector <map<string, string>> Csv::read(const string& file, const char delimiter) {

    string line, columnName;
    vector <map<string, string>> result;
    int columnIndex = 0;

    ifstream myFile(file);
    if (myFile.good()) {
        // Extract the first line in the file
        getline(myFile, line);

        // Create a string stream from line
        stringstream ss(line);

        // Create a temporary map for the column names in order to create a map file containing each column name as key
        map<int, string> columns;

        // Extract each column name
        while (getline(ss, columnName, delimiter)) {
            columns.emplace(columnIndex, columnName);
            ++columnIndex;
        }

        // Extract other lines
        map <string, string> lineResult;
        string value;
        while (!myFile.eof()) {
            lineResult.clear();
            getline(myFile, line);
            stringstream ss2(line);
            columnIndex = 0;
            // Add data if the line is not empty
            if (!ss2.str().empty()) {
                while (getline(ss2, value, ';')) {
                    string currentColumnName = columns.find(columnIndex) != columns.end() ? columns.at(columnIndex) : "None";
                    lineResult.emplace(currentColumnName, value);
                    ++columnIndex;
                }
                result.emplace_back(lineResult);
            }
        }

        // Close file
        myFile.close();
    } else {
        cout << "Unable to open the CSV file: " << file << endl;
    }

    return result;
}