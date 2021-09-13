#ifndef TESTCPP2_CSV_H
#define TESTCPP2_CSV_H

#include <map>
#include <string>
#include <vector>

class Csv {
public:
    /**
     * Parse a csv file and return a map containing the key value pairs
     * @param file Path of the file to open
     * @param delimiter Delimiter of the columns on the CSV file
     * @return Map containing the key value pairs
     */
    static std::vector <std::map<std::string, std::string>> read(const std::string& file, char delimiter);
};


#endif
