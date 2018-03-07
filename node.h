#ifndef NODE_H
#define NODE_H

#include <string>

using std::string;

// Node class
class Node {
    string data;
    Node* next;

  public:
    Node() {};
    void SetData(string aData) { data = aData; };
    void SetNext(Node* aNext = NULL) { next = aNext; };
    string Data() { return data; };
    Node* Next() { return next; };
};
#endif /* NODE_H */
