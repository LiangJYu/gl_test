#include <iostream>
#include <fstream>

#include "contact_list.h"

using std::cout;
using std::cin;

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

void contact_list::run()
{
    int usr_input = -1; 
    while (usr_input != 0)
    {
        this->show_options();
        std::cin >> usr_input;

        string name;
        bool del = false;
        switch (usr_input) {
            case 0:
                cout << "quitting application\n";
                break;
            case 1:
                list.Print();
                break;
            case 2:
                cout << "Enter name to find: ";
                cin >> name;
                list.find_maybe_delete(name, del) ;
                break;
            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                del = true;
                list.find_maybe_delete(name, del);
                break;
            default:
                cout << usr_input << " invalid. Choose again.\n";
                break;
        }
    }
}
