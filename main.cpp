#include <string>
#include <istream>
#include <sstream>
#include <vector>
#include <iostream>

#include "csv.h"

int main()
{
    std::cout << "Hello\n";

    csv my_csv = csv();
    my_csv.read_file();

    std::string usr_input;
    std::cout << usr_input;    while (usr_input != "q")
    {
        std::cout << "enter something: ";
        std::getline(std::cin, usr_input);
    }
    return 0;
}
