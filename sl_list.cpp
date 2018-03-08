#include <iostream>
#include <string>
#include "sl_list.h"

using std::cout;
using std::endl;
using std::string;

void List::Print() {

    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "EMPTY" << endl;
        return;
    }
    else
    {

        if (tmp->Next() != NULL)
        {
            while (tmp->Next() != NULL)
            {
                cout << tmp->Data() << endl;
                tmp = tmp->Next();
            }
        }
        else
        // One node in the list
        {
            cout << tmp->Data() << endl;
        }
    }
}

/**
 * Append a node to the linked list
 */
void List::Append(string data) {

    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

    // Point the last node to the new node
    tmp->SetNext(newNode);
    }
    else {
    // First node in the list
    head = newNode;
    }
}

/**
 * Find a node from the list and maybe delete it
 */
void List::find_maybe_delete(string name, bool del) 
{
    // Temp pointer
    Node *tmp = head;

    string report = del ? " deleted\n" : " found\n"; 

    // No nodes
    if ( tmp == NULL ) 
    {
        cout << "EMPTY" << endl;
    }
    else
    {
        // check if only 1 element has name
        if (tmp->Next() == NULL && tmp->Data() == name)
        {
            if (del)
            {
                delete tmp;
                head = NULL;
            }
            cout << name << report;
        }
        // loop thru and check other elements for name
        else
        {
            Node *prev = head;
            // check for name match or end of list
            while (tmp->Data() != name && tmp->Next() != NULL)
            {
                prev = tmp;
                tmp = tmp->Next();
            }
            // check if name match is found
            if (tmp->Data() == name)
            {
                if (del) {
                    prev->SetNext(tmp->Next());
                    delete tmp;
                }
                cout << name << report;
            }
        }
    }
}
