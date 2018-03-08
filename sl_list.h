#ifndef SL_LIST_H
#define SL_LIST_H

#include <string>
#include "node.h"

using std::string;
// List class
class List {
        Node *head;
        bool find_maybe_delete(string name, bool del) ;
    public:
        List() { head = NULL; };
        void print_to_screen();
        void print_to_file();
        void append(string data);
        bool find(string name);
        bool erase(string name);
};

#endif /* SL_LIST_H */
