#include "lists.h"

int main()
{

    list list = {};

    list_ctor(&list);

    list_add(&list, 0, 10);
    list_add(&list, 1, 20);
    list_add(&list, 14, 30);
    list_add(&list, 13, 40);
    list_add(&list, 13, 50);
    list_dump(&list);

    list_dtor(&list);


    return 0;
}