#include <string>
#include <istream>
#include <sstream>
#include <vector>
#include <iostream>

#include "contact_list.h"

int main()
{
    std::cout << "Hello\n";

    contact_list my_list = contact_list();
    my_list.read_csv_to_list();

    my_list.run();
    return 0;
}
