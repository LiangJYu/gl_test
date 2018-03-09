#include "CppUTest/TestHarness.h"
#include "sl_list.h"
#include "quicksort.h"

TEST_GROUP(sl_list_group)
{
    void setup()
    {
        sl_list list;
        list.append("b,1");
        list.append("e,1");
        list.append("a,1");
        list.append("c,1");
        list.append("d,1");

        Node *n = list.get_head();
        quick_sort(&n);
    }
}

// succeed at finding "a"
TEST(sl_list_group, test_find_success)
{
    CHECK(list.find("a"));
}

// fail at finding non existant "z"
TEST(sl_list_group, test_find_fail)
{
    CHECK_FALSE(list.find("z"));
}

// succeed at finding "d"
TEST(sl_list_group, test_erase_success)
{
    CHECK(list.erase("d"));
}

// fail at erasing non existant "Z"
TEST(sl_list_group, test_erase_fail)
{
    CHECK_FALSE(list.erase("z"));
}

// check if head of sorted result is correct
TEST(sl_list_group, test_sort)
{
    Node *n = list.get_head();
    CHECK_EQUAL(n->data == "a,1");
}

// check if end of sorted result is correct
TEST(sl_list_group, test_get_tail)
{
    Node *n = list.get_head();
    Node *m = get_tail(n);
    CHECK_EQUAL(m->data == "e,1");
}
