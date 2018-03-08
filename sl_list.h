#ifndef SL_LIST_H
#define SL_LIST_H

#include <string>
#include "node.h"

using std::string;

class sl_list {
    friend class contact_list;
    private:
        Node *head;
        bool find_maybe_delete(string name, bool del) ;
    public:
        sl_list() { head = NULL; };
        void append(string data);
        bool find(string name);
        bool erase(string name);
        Node* get_head() { return head; };
};

#endif /* SL_LIST_H */
