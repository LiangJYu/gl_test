#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include "contact_list.h"

using std::cout;
using std::cin;

/*
* read CSV from file to list
*/
bool contact_list::read_csv_to_list()
{
    // open file 
    // TODO take in arg from interface 
    string fpath = "data.csv";
    struct stat buffer;
    if ( stat(fpath.c_str(), &buffer) == 0 )
    {
        std::ifstream ifs(fpath.c_str(), std::ifstream::in);

        // get header and discard
        string value;
        std::getline(ifs, value);
        // get lines while they're there
        while(ifs.good())
        {
            std::getline(ifs, value);
            list.append(value);
        }
        cout << "csv loaded\n";
        return true;
    }
    else
    {
        return false;
    }
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
