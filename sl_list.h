#ifndef SL_LIST_H
#define SL_LIST_H

#include <string>
#include "node.h"

using std::string;
// List class
class List {
        Node *head;
        void find_maybe_delete(string name, bool del) ;
    public:
        List() { head = NULL; };
        void print();
        void append(string data);
        void find(string name);
        void erase(string name);
};

#endif /* SL_LIST_H */
