#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <string>
#include "sl_list.h"

class contact_list
{
    sl_list list;

    void show_options();

    public:
        void print_to_screen();
        void print_to_file();
        bool read_csv_to_list();
        void run();
};

#endif /* CONTACT_LIST_H */
