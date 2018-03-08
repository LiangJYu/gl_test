#ifndef NODE_H
#define NODE_H

#include <string>

using std::string;

// Node class
// for ease, storing entire line i.e.: name,number
// ideally this should be templated for ease
struct Node {
    string data; 
    Node* next;
    
};
#endif /* NODE_H */
