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
        void find_maybe_delete(string name, bool del) ;
};

#endif /* SL_LIST_H */
