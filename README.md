# CSV Reader C++

Simple class to read CSV data and construct a C++ vector containing maps of each column of the lines, with the column name as key.

## Usage

```c++
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
```

## Example

Example of output with the CSV file `example.csv`.

Content of the CSV file:

```text
id;name;description;amount
0;test;test description;12
1;test2;test description 2;15
```

Output with the example code above:

```text
amount: 12
description: test description
id: 0
name: test
Description: test description
amount: 15
description: test description 2
id: 1
name: test2
Description: test description 2
```

# Licence

Author: Romain Garcia

Copyright 2021, Romain Garcia

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.