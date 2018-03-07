#include <iostream>
#include <fstream>

#include "contact_list.h"

using std::cout;

void contact_list::read_csv_to_list()
{
    std::ifstream ifs ("data.csv", std::ifstream::in);
    string value;
    std::size_t found;
    
    std::getline(ifs, value);
    while(ifs.good())
    {
        std::getline(ifs, value);
        found = value.find(',');
        string name = value.substr(0, found);
        list.Append(name);
    }
    cout << "csv loaded\n";
}

void contact_list::show_options()
{
    cout << "\nOptions:\n"
            "1: print entire contact list\n"
            "2: find contact by name\n"
            "3: delete contact by name\n"
            "0: quit application\n"
            "choose an option: ";
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
    int usr_input = -1; 
    while (usr_input != 0)
    {
        this->show_options();
        std::cin >> usr_input;

        switch (usr_input) {
            case 0:
                cout << "quitting application\n";
                break;
            case 1:
                list.Print();
                break;
            default:
                cout << usr_input << " invalid. Choose again.\n";
                break;
        }
    }
}
