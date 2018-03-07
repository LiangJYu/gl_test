#include <iostream>

#include "csv.h"

void csv::read_file()
{
    std::ifstream ifs ("data.csv", std::ifstream::in);
    std::string value;
    std::size_t found;
    
    while(ifs.good())
    {
        std::getline(ifs, value);
        found = value.find(',');
        std::cout << "name:" << value.substr(0, found);
        std::cout << " number: " << value.substr(found+1) << std::endl;
    }
}
