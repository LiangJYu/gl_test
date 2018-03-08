#include <iostream>
#include <string>
#include <fstream>
#include "sl_list.h"

using std::cout;
using std::endl;
using std::string;

/**
* Print list; all of it
*/
void List::print(bool to_file) {

    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "EMPTY" << endl;
        return;
    }
    else
    {

        std::ofstream out("serial.out");
        if (to_file)
            out << "backup\n";  // throwaway top line to match csv
        if (tmp->get_next() != NULL)
        {
            while (tmp->get_next() != NULL)
            {
                if (to_file)
                    out << tmp->get_data() << endl;
                else
                    cout << tmp->get_data() << endl;
                tmp = tmp->get_next();
            }
        }
        else
        // One node in the list
        {
            if (to_file)
                out << tmp->get_data();
            else
                cout << tmp->get_data() << endl;
        }
        out.close();
    }
}

void List::print_to_file()
{
    bool to_file =  true;
    print(to_file);
}


 /**
 * Append a node to the linked list
 */
 void List::append(string data) {

    // Create a new node
    Node* new_node = new Node();
    new_node->set_data(data);
    new_node->set_next(NULL);

    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->get_next() != NULL ) {
            tmp = tmp->get_next();
        }

        // Point the last node to the new node
        tmp->set_next(new_node);
    }
    else {
    // First node in the list
     head = new_node;
     }
 }

/*
* wrapper function to check if name in data using string::find
*/
bool has_name(Node* n, string name)
{
    std::size_t found = n->get_data().find(name);
    if (found == string::npos)
        return false;
    else
        return true;
}

/**
* Find a node from the list and maybe delete it
* Recycled loop code for find and delete
* input: 
*   string  - name  - who to find to delete or print
*   bool    - del   - true: delete if name found, else print contact
*/
bool List::find_maybe_delete(string name, bool del) 
{
    bool found = false;

    // Temp pointer
    Node *tmp = head;

    string report = del ? "Deleting: " : "Found: "; 

    // No nodes
    if ( tmp == NULL ) 
    {
        cout << "EMPTY" << endl;
    }
    else
    {
        // check if only 1 element has name
        //if (tmp->get_next() == NULL && tmp->get_data() == name)
        if (tmp->get_next() == NULL && has_name(tmp, name))
        {
            found = true;
            cout << report << tmp->get_data() << endl;
            if (del)
            {
                delete tmp;
                head = NULL;
            }
        }
        // loop thru and check other elements for name
        else
        {
            Node *prev = head;
            // check for name match or end of list
            //while (tmp->get_data() != name && tmp->get_next() != NULL)
            while (!has_name(tmp, name) && tmp->get_next() != NULL)
            {
                prev = tmp;
                tmp = tmp->get_next();
            }
            // check if name match is found
            //if (tmp->get_data() == name)
            if (has_name(tmp, name))
            {
                found = true;
                cout << report << tmp->get_data() << endl;
                if (del) {
                    prev->set_next(tmp->get_next());
                    delete tmp;
                }
            }
        }
    }
    return found;
}

/*
* wrapper around find_maybe_delete for finding something
*/
bool List::find(string name)
{
    bool del = false;
    return find_maybe_delete(name, del);
}

/*
* wrapper around find_maybe_delete for deleting something
*/
bool List::erase(string name)
{
    bool del = true;
    return find_maybe_delete(name, del);
}
