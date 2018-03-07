#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <string>
#include "sl_list.h"

class contact_list
{
    List list;

    public:
        void read_csv_to_list();
        bool find_contact(string);
        bool delete_contact(string);
        void run();
};

#endif /* CONTACT_LIST_H */
