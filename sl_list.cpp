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
 * Delete a node from the list
 */
void List::Delete(string data) {

    // Create a temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL )
    return;

    // Last node of the list
    if ( tmp->Next() == NULL ) {
    delete tmp;
    head = NULL;
    }
    else {
    // Parse thru the nodes
    Node *prev = NULL;
    do {
        if ( tmp->Data() == data ) break;
        prev = tmp;
        tmp = tmp->Next();
    } while ( tmp != NULL );

    // Adjust the pointers
    prev->SetNext(tmp->Next());

    // Delete the current node
    delete tmp;
    }
}
