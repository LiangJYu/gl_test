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

    // instaniate list
    contact_list my_list = contact_list();

    // kick off loop
    my_list.run();
    return 0;
}
