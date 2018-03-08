#include <iostream>
#include <string>
#include "sl_list.h"

using std::cout;
using std::endl;
using std::string;

/**
* Print list; all of it
*/
void List::print() {

    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "EMPTY" << endl;
        return;
    }
    else
    {

        if (tmp->get_next() != NULL)
        {
            while (tmp->get_next() != NULL)
            {
                cout << tmp->get_data() << endl;
                tmp = tmp->get_next();
            }
        }
        else
        // One node in the list
        {
            cout << tmp->get_data() << endl;
        }
    }
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

/**
* Find a node from the list and maybe delete it
* Recycled loop code for find and delete
* input: 
*   string  - name  - who to find to delete or print
*   bool    - del   - true: delete if name found, else print contact
*/
void List::find_maybe_delete(string name, bool del) 
{
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
        if (tmp->get_next() == NULL && tmp->get_data() == name)
        {
            cout << report << tmp->get_data();
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
            while (tmp->get_data() != name && tmp->get_next() != NULL)
            {
                prev = tmp;
                tmp = tmp->get_next();
            }
            // check if name match is found
            if (tmp->get_data() == name)
            {
                cout << report << tmp->get_data();
                if (del) {
                    prev->set_next(tmp->get_next());
                    delete tmp;
                }
            }
        }
    }
}
