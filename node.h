#ifndef NODE_H
#define NODE_H

#include <string>

using std::string;

// Node class
// for ease, storing entire line i.e.: name,number
// ideally this should be templated for ease
class Node {
    string data; 
    Node* next;

  public:
    Node() {};
    void set_data(string aData) { data = aData; };
    void set_next(Node* aNext = NULL) { next = aNext; };
    string get_data() { return data; };
    Node* get_next() { return next; };
};
#endif /* NODE_H */
