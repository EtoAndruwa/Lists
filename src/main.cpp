#include "lists.h"

int main()
{

    list list = {};

    list_ctor(&list);

    logic(&list);

    list_dtor(&list);


    return 0;
}

