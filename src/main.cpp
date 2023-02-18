#include "lists.h"

int main()
{

    list list = {};

    list_ctor(&list);

    list_dump(&list);

    list_dtor(&list);


    return 0;
}