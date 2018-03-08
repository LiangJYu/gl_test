#include <string>
#include <istream>
#include <sstream>
#include <vector>
#include <iostream>

#include "contact_list.h"

int main()
{
    // be polite and greet user
    std::cout << "Hello\n";

    // load list
    contact_list my_list = contact_list();
    my_list.read_csv_to_list();

    // kick off loop
    my_list.run();
    return 0;
}
