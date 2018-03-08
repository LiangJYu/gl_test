#include <iostream>
#include <fstream>

#include "contact_list.h"

using std::cout;
using std::cin;

/*
* read CSV from file to list
*/
void contact_list::read_csv_to_list()
{
    // open file 
    // TODO take in arg from interface 
    // TODO check if file exists
    std::ifstream ifs ("data.csv", std::ifstream::in);

    // declare values for later
    string value;
    std::size_t found;
    
    // get header and discard
    std::getline(ifs, value);
    // get lines while they're there
    while(ifs.good())
    {
        std::getline(ifs, value);
        found = value.find(',');
        string name = value.substr(0, found);
        list.append(name);
    }
    cout << "csv loaded\n";
}

/*
* print options
*/
void contact_list::show_options()
{
    cout << "\nOptions:\n"
            "1: print entire contact list\n"
            "2: find contact by name\n"
            "3: delete contact by name\n"
            "0: quit application\n"
            "choose an option: ";
}

/*
* loop that drives contact list
*/
void contact_list::run()
{
    int usr_input = -1; 
    // keep going until user says stop
    while (usr_input != 0)
    {
        // show options and get input then go
        this->show_options();
        std::cin >> usr_input;

        string name;
        switch (usr_input) {
            case 0:
                cout << "quitting application\n";
                break;
            case 1:
                list.print();
                break;
            case 2:
                cout << "Enter name to find: ";
                cin >> name;
                list.find(name);
                break;
            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                list.erase(name);
                break;
            default:
                cout << usr_input << " invalid. Choose again.\n";
                break;
        }
    }
}
