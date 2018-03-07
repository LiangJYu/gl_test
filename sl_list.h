#ifndef SL_LIST_H
#define SL_LIST_H

#include <string>
#include "node.h"

using std::string;
// List class
class List {
        Node *head;
    public:
        List() { head = NULL; };
        void Print();
        void Append(string data);
        void Delete(string data);
};

#endif /* SL_LIST_H */
