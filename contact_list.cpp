#include <iostream>
#include <fstream>

#include "contact_list.h"

using std::cout;

void contact_list::read_csv_to_list()
{
    std::ifstream ifs ("data.csv", std::ifstream::in);
    string value;
    std::size_t found;
    
    while(ifs.good())
    {
        std::getline(ifs, value);
        found = value.find(',');
        string name = value.substr(0, found);
        list.Append(name);
        cout << "name:" << value.substr(0, found);
        cout << " number: " << value.substr(found+1) << std::endl;

    }
}

bool contact_list::find_contact(string name)
{
    list.Delete(name);
    return true;
}

bool contact_list::delete_contact(string name)
{
    list.Delete(name);
    return true;
}

void contact_list::run()
{
    std::string usr_input;
    std::cout << usr_input;    
    while (usr_input != "q")
    {
        std::cout << "enter something: ";
        std::getline(std::cin, usr_input);
    }
}
